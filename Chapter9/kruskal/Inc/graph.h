#pragma once
/*
 * @Author: your name
 * @Date: 2020-03-01 16:19:01
 * @LastEditTime: 2020-03-07 17:54:29
 * @LastEditors: Please set LastEditors
 * @Description: 图应用之拓扑排序
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
	// 放入顶点
	void pushENode(Comparable data)
	{
		VNode* pNode = new VNode{ data };
		vexs.push_back(*pNode);
		delete pNode;
	}
	// 设置边 vdata 顶点 edata 邻接点 weight 权重
	void setEdge(Comparable vdata, Comparable edata, int weight = 1)
	{
		typename VNode::ENode* pNode = new typename VNode::ENode{ get_position(vdata), get_position(edata), weight };
		get_position(vdata)->medges.push_back(*pNode);
		delete pNode;
	}
	// 拓扑排序
	void topsort()
	{
		int counter = 0;
		updataIndegree();
		std::queue< Iterator > q;
		for (auto it = vexs.begin(); it != vexs.end(); ++it)
			if (it->mindegree == 0)
				q.push(it);                       // 入队

		while (!q.empty())
		{
			Iterator v = q.front();
			q.pop();                               // 出队
			v->mtopNum = ++counter;
			for (auto& w : v->medges)
				if (--w.mit->mindegree == 0)
					q.push(w.mit);                // 入队
		}

		if (counter != vexs.size())
			throw CycleFoundException{ };
	}

	// 最短路径之广度优先搜索
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
	// 得到from到to之间的最短路径
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
	// 最短路径之迪杰斯特拉算法 
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
	// 最小生成树之 prim 算法
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
	// 最小生成树之 kruskal 算法
	void kruskal()
	{
		DisjSets ds(vexs.size());
		std::priority_queue < typename VNode::ENode,
			std::vector< typename VNode::ENode >,
			typename VNode::cmp > pq;	// 创建堆

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
	// 具有负边的图的最短路径
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
						w.mit->inqueue = true;                      // 标记顶点已进入队列
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

	// 邻接表中表的顶点
	struct VNode
	{
		// 邻接表中表对应的链表节点
		struct ENode
		{
			typename std::vector<VNode>::iterator mpit;				// 改变的起点顶点的位置
			typename std::vector<VNode>::iterator mit;              // 该边的终点顶点的位置                                
			int mweight;                                            // 该边的权重
			ENode(typename std::vector<VNode>::iterator pit,
				typename std::vector<VNode>::iterator it, int weight)
				: mpit{ pit }, mit{ it }, mweight{ weight }
			{

			}
		};
		Comparable mdata;                                           // 顶点信息
		int mindegree;                                              // 入度
		int mtopNum;                                                // 拓扑号

		int dist;                                                   // 距离
		typename std::vector<VNode>::iterator path;                 // 路径

		bool known;				                                    // 标记顶点是否已在队列中
		bool inqueue;

		std::list< ENode >  medges;                                 // 该顶点的邻接边的链表  
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

	// 返回节点所在位置
	Iterator get_position(Comparable element)
	{
		for (auto it = vexs.begin(); it != vexs.end(); ++it)
			if (it->mdata == element)
				return it;
		throw ArrayIndexOutOfBoundsException{ };
	}
	// 得到边的起点
	inline int getu(typename VNode::ENode edge)
	{
		for (int i = 0; i < vexs.size(); ++i)
			if (edge.mpit->mdata == vexs[i].mdata)
				return i;
		throw ArrayIndexOutOfBoundsException{ };
	}
	// 得到边的终点
	inline int getv(typename VNode::ENode edge)
	{
		for (int i = 0; i < vexs.size(); ++i)
			if (edge.mit->mdata == vexs[i].mdata)
				return i;
		throw ArrayIndexOutOfBoundsException{ };
	}
	// 更新入度
	void updataIndegree()
	{
		for (auto node : vexs)
			for (auto x : node.medges)
				++x.mit->mindegree;
	}
	// 得到 from 到 to 之间路径内部方法
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
	int vexnum;                         // 图的顶点数目
	int edgnum;                         // 图的边的数目
	std::vector< VNode > vexs;          // 图顶点储存容器

};
