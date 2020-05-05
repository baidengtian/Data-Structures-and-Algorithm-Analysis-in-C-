#pragma once
/*
 * @Author: your name
 * @Date: 2020-03-01 16:19:01
 * @LastEditTime: 2020-03-07 17:54:29
 * @LastEditors: Please set LastEditors
 * @Description: ͼӦ��֮��������
 * @FilePath: \topsort\Inc\graph.h
 */

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include "dsexceptions.h"
#include <climits>
#include "DisjSets.h"

template < typename Comparable >
class graph
{
public:

	graph(int vnum, int ednum)
		: vexnum{ vnum }, edgnum{ ednum }
	{

	}
	graph()
		: vexnum{ 0 }, edgnum{ 0 }
	{

	}
	// ���붥��
	void pushENode(Comparable data)
	{
		VNode* pNode = new VNode{ data };
		vexs.push_back(*pNode);
		delete pNode;
	}
	// ���ñ� vdata ���� edata �ڽӵ� weight Ȩ��
	void setEdge(Comparable vdata, Comparable edata, int weight = 1)
	{
		typename VNode::ENode* pNode = new typename VNode::ENode{ get_position(vdata), get_position(edata), weight };
		get_position(vdata)->medges.push_back(*pNode);
		delete pNode;
	}
	// ��������
	void topsort()
	{
		int counter = 0;
		updataIndegree();
		std::queue< Iterator > q;
		for (auto it = vexs.begin(); it != vexs.end(); ++it)
			if (it->mindegree == 0)
				q.push(it);                       // ���

		while (!q.empty())
		{
			Iterator v = q.front();
			q.pop();                               // ����
			v->mtopNum = ++counter;
			for (auto& w : v->medges)
				if (--w.mit->mindegree == 0)
					q.push(w.mit);                // ���
		}

		if (counter != vexs.size())
			throw CycleFoundException{ };
	}

	// ���·��֮�����������
	void unweighted(Comparable s)
	{
		std::queue< Iterator > q;
		Iterator it = get_position(s);
		it->dist = 0;
		q.push(it);
		while (!q.empty())
		{
			Iterator v = q.front();
			q.pop();
			for (auto w : v->medges)
				if (w.mit->dist == INT_MAX)
				{
					w.mit->dist = v->dist + 1;
					w.mit->path = v;
					q.push(w.mit);
				}
		}
	}
	enum option { unweightedsearch, dijkstrasearch };
	// �õ�from��to֮������·��
	void getPath(int searchoption, Comparable from, Comparable to)
	{
		switch (searchoption)
		{
		case graph::unweightedsearch:
			unweighted(from);
			break;
		case graph::dijkstrasearch:
			dijkstra(from);
			break;
		default:
			break;
		}
		// unweighted( from );
		// dijkstra( from );
		getPath(get_position(from), get_position(to));
	}
	// ���·��֮�Ͻ�˹�����㷨 
	void dijkstra(Comparable s)
	{
		auto it = get_position(s);
		it->dist = 0;
		std::queue< Iterator > q;
		q.push(it);
		while (!q.empty())
		{
			Iterator v = q.front();
			q.pop();
			for (auto w : v->medges)
				if (v->dist + w.mweight < w.mit->dist)
				{
					w.mit->dist = v->dist + w.mweight;
					w.mit->path = v;
					q.push(w.mit);
				}
		}
	}
	// ��С������֮ prim �㷨
	void prim()
	{
		int count = 1;
		Iterator it = vexs.begin();
		it->dist = 0;
		it->known = true;
		std::priority_queue < typename VNode::ENode,
			std::vector< typename VNode::ENode >,
			typename VNode::cmp > q;
		for (auto x : it->medges)
			q.push(x);
		while (count != vexs.size())
		{
			auto v = q.top();
			q.pop();
			if (!v.mit->known)
			{
				v.mit->path = v.mpit;
				v.mit->known = true;
				v.mit->dist = v.mweight;

				for (auto w : v.mit->medges)
					q.push(w);
				count++;
			}
		}
	}
	// ��С������֮ kruskal �㷨
	void kruskal()
	{
		DisjSets ds(vexs.size());
		std::priority_queue < typename VNode::ENode,
			std::vector< typename VNode::ENode >,
			typename VNode::cmp > pq;	// ������

		for (auto v : vexs)
			for (auto w : v.medges)
				pq.push(w);

		std::vector< typename VNode::ENode > mst;

		while (mst.size() != vexs.size() - 1)
		{
			typename VNode::ENode e = pq.top();
			pq.pop();
			int uset = ds.find(getu(e));
			int vset = ds.find(getv(e));

			if (uset != vset)
			{
				std::cout << "( " << e.mpit->mdata << " , " << e.mit->mdata << " ) " << std::endl;
				mst.push_back(e);
				ds.unionSets(uset, vset);
			}

		}

	}
	// ���и��ߵ�ͼ�����·��
	void weightedNegative(Comparable s)
	{
		auto it = get_position(s);
		it->dist = 0;
		it->inqueue = true;
		std::queue< Iterator > q;
		q.push(it);
		while (!q.empty())
		{
			Iterator v = q.front();
			q.pop();
			v->inqueue = false;
			for (auto w : v->medges)
				if (v->dist + w.mweight < w.mit->dist)
				{
					w.mit->dist = v->dist + w.mweight;
					w.mit->path = v;
					if (!w.mit->inqueue)
					{
						w.mit->inqueue = true;                      // ��Ƕ����ѽ������
						q.push(w.mit);
					}

				}
		}
	}
	void print()
	{
		// for( auto node : vexs )
		//     std::cout << node.mtopNum << "  ";
		// std::cout << std::endl;
		// for( auto node : vexs )
		//     std::cout << node.dist << "  ";
		// std::cout << std::endl;
		for (auto node : vexs)
			std::cout << node.dist << "  ";
		std::cout << std::endl;
	}
private:

	// �ڽӱ��б�Ķ���
	struct VNode
	{
		// �ڽӱ��б��Ӧ������ڵ�
		struct ENode
		{
			typename std::vector<VNode>::iterator mpit;				// �ı����㶥���λ��
			typename std::vector<VNode>::iterator mit;              // �ñߵ��յ㶥���λ��                                
			int mweight;                                            // �ñߵ�Ȩ��
			ENode(typename std::vector<VNode>::iterator pit,
				typename std::vector<VNode>::iterator it, int weight)
				: mpit{ pit }, mit{ it }, mweight{ weight }
			{

			}
		};
		Comparable mdata;                                           // ������Ϣ
		int mindegree;                                              // ���
		int mtopNum;                                                // ���˺�

		int dist;                                                   // ����
		typename std::vector<VNode>::iterator path;                 // ·��

		bool known;				                                    // ��Ƕ����Ƿ����ڶ�����
		bool inqueue;

		std::list< ENode >  medges;                                 // �ö�����ڽӱߵ�����  
		VNode(Comparable data)
			: mdata{ data }, mindegree{ 0 }, mtopNum{ 0 },
			dist{ INT_MAX }, inqueue{ false }, known{ false }

		{

		}
		struct cmp
		{
			bool operator ()(ENode x, ENode y)
			{
				return x.mweight > y.mweight;
			}
		};

	};
	typedef typename std::vector<VNode>::iterator Iterator;

	// ���ؽڵ�����λ��
	Iterator get_position(Comparable element)
	{
		for (auto it = vexs.begin(); it != vexs.end(); ++it)
			if (it->mdata == element)
				return it;
		throw ArrayIndexOutOfBoundsException{ };
	}
	// �õ��ߵ����
	inline int getu(typename VNode::ENode edge)
	{
		for (int i = 0; i < vexs.size(); ++i)
			if (edge.mpit->mdata == vexs[i].mdata)
				return i;
		throw ArrayIndexOutOfBoundsException{ };
	}
	// �õ��ߵ��յ�
	inline int getv(typename VNode::ENode edge)
	{
		for (int i = 0; i < vexs.size(); ++i)
			if (edge.mit->mdata == vexs[i].mdata)
				return i;
		throw ArrayIndexOutOfBoundsException{ };
	}
	// �������
	void updataIndegree()
	{
		for (auto node : vexs)
			for (auto x : node.medges)
				++x.mit->mindegree;
	}
	// �õ� from �� to ֮��·���ڲ�����
	void getPath(Iterator from,
		Iterator to)
	{
		if (to != from)
		{
			getPath(from, to->path);
			std::cout << "-->>";
		}

		std::cout << to->mdata;
	}
	int vexnum;                         // ͼ�Ķ�����Ŀ
	int edgnum;                         // ͼ�ıߵ���Ŀ
	std::vector< VNode > vexs;          // ͼ���㴢������

};
