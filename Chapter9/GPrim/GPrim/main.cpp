///*
// * @Author: lsyy
// * @Date: 2020-03-03 17:49:23
// * @LastEditTime: 2020-03-06 20:59:30
// * @LastEditors: Please set LastEditors
// * @Description: stl��ʵ��ͼ�ṹ����ͨ��������������õ����������Ȩ���·��
// * @FilePath: \graph++\Src\main.cpp
// */
//
//#include <iostream>
//#include "graph.h"
//#include <list>
//#include <queue>
//#include <unordered_map>        // �ڲ�ʵ���ǹ�ϣ�� ����O(1)
//#include <string>
//#include <algorithm>
//
//
// /**
//  * @description: ��Ȩ���·�������������
//  * @param {type} adjacentWords ͼ first �������
//  * @return: �����ýڵ�ǰһ���ڵ��map����
//  */
//std::unordered_map< std::string, std::string >
//findChain(const std::unordered_map< std::string, std::vector< std::string > >& adjacentWords,
//	const std::string& first)
//{
//	std::unordered_map< std::string, std::string > previousWords;
//	std::queue< std::string > q;
//	q.push(first);
//	while (!q.empty())
//	{
//		std::string current = q.front();
//		q.pop();
//		auto itr = adjacentWords.find(current);
//
//		const std::vector< std::string >& adj = itr->second;
//
//		for (auto& str : adj)
//			if (previousWords[str] == "")
//			{
//				previousWords[str] = current;
//				q.push(str);
//			}
//	}
//	previousWords[first] = "";
//	return previousWords;
//}
//std::vector< std::string > getChainFormPreviousMap(
//	const std::unordered_map< std::string, std::string >& previous, const std::string& second)
//{
//	std::vector< std::string > result;
//	// const �Ͳ���ʹ�� operator[] �����Ҫǿ��ת��
//	auto& prev = const_cast<std::unordered_map< std::string, std::string >&> (previous);
//	for (std::string current = second; current != ""; current = prev[current])
//		result.push_back(current);
//
//	std::reverse(std::begin(result), std::end(result));   // ˳���Ϊ����
//	return result;
//}
///**
// * @description: �õ� first �� second ֮������·��
// * @param {type} adjacentWords ͼ first ��� second �յ�
// * @return: ·��
// */
//std::vector< std::string > getPath(
//	const std::unordered_map< std::string, std::vector< std::string > > & adjacentWords,
//	const std::string & first, const std::string & second)
//{
//	return getChainFormPreviousMap(findChain(adjacentWords, first), second);
//}
//#include <string>
//
//int main()
//{
//	std::string s("abcd");
//	const char* sc = "abcd";
//
//	return 0;
//}

//int main()
//{
//	graph< int > gh;
//	gh.pushENode(1);
//	gh.pushENode(2);
//	gh.pushENode(3);
//	gh.pushENode(4);
//	gh.pushENode(5);
//	gh.pushENode(6);
//	gh.pushENode(7);
//
//	gh.setEdge(1, 2, 2);
//	gh.setEdge(1, 3, 4);
//	gh.setEdge(1, 4, 1);
//
//	gh.setEdge(2, 1, 2);
//	gh.setEdge(2, 4, 3);
//	gh.setEdge(2, 5, 10);
//
//	gh.setEdge(3, 1, 4);
//	gh.setEdge(3, 4, 2);
//	gh.setEdge(3, 6, 5);
//
//	gh.setEdge(4, 1, 1);
//	gh.setEdge(4, 2, 3);
//	gh.setEdge(4, 3, 2);
//	gh.setEdge(4, 5, 7);
//	gh.setEdge(4, 6, 8);
//	gh.setEdge(4, 7, 4);
//
//	gh.setEdge(5, 2, 10);
//	gh.setEdge(5, 4, 7);
//	gh.setEdge(5, 7, 6);
//
//	gh.setEdge(6, 3, 5);
//	gh.setEdge(6, 4, 8);
//	gh.setEdge(6, 7, 1);
//
//	gh.setEdge(7, 6, 1);
//	gh.setEdge(7, 4, 4);
//	gh.setEdge(7, 5, 6);
//
//	// gh.topsort( );
//	gh.kruskal();
//	// gh.prim( );
//	// gh.print( );
//	return 0;
//}
#include <iostream>
#include <vector>

long long fibonacci(int n)
{
	if (n <= 1)
		return 1;
	
	long long last = 1;
	long long nextToLast = 1;
	long long answer = 1;

	for (int i = 2; i <= n; ++i)
	{
		answer = last + nextToLast;
		nextToLast = last;
		last = answer;
	}
	return answer;
}
double eval(int n)
{
	double sum = 1.0;
	double ci = 1.0;
	if (n <= 1)
		return 1;
	for (int i = 1; i <= n; ++i)
	{
		ci = ( 2.0 / i ) * sum + i;
		sum += ci;
	}
	return ci;
}
double getval(int n)
{
	std::vector<double> c(n + 1);
	c[0] = 1.0;
	for (int i = 1; i <= n; ++i)
	{
		double sum = 0.0;
		for (int j = 0; j < i; ++j)
			sum += c[j];
		c[i] = 2.0 * sum / i + i;
	}
	return c[n];
}
int main()
{

	std::cout << eval( 20 ) << "	" << getval( 20 ) << std::endl;
	return 0;
}