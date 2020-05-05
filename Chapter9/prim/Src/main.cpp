/*
 * @Author: lsyy
 * @Date: 2020-03-03 17:49:23
 * @LastEditTime: 2020-03-07 16:29:07
 * @LastEditors: Please set LastEditors
 * @Description: stl库实现图结构并且通过广度优先搜索得到两顶点间无权最短路径
 * @FilePath: \graph++\Src\main.cpp
 */

#include <iostream>
#include "graph.h"
#include <list>
#include <queue>
#include <unordered_map>        // 内部实现是哈希表 查找O(1)
#include <string>
#include <algorithm>


 /**
  * @description: 无权最短路径广度优先搜索
  * @param {type} adjacentWords 图 first 搜索起点
  * @return: 包含该节点前一个节点的map容器
  */
std::unordered_map< std::string, std::string >
findChain(const std::unordered_map< std::string, std::vector< std::string > >& adjacentWords,
	const std::string& first)
{
	std::unordered_map< std::string, std::string > previousWords;
	std::queue< std::string > q;
	q.push(first);
	while (!q.empty())
	{
		std::string current = q.front();
		q.pop();
		auto itr = adjacentWords.find(current);

		const std::vector< std::string >& adj = itr->second;

		for (auto& str : adj)
			if (previousWords[str] == "")
			{
				previousWords[str] = current;
				q.push(str);
			}
	}
	previousWords[first] = "";
	return previousWords;
}
std::vector< std::string > getChainFormPreviousMap(
	const std::unordered_map< std::string, std::string >& previous, const std::string& second)
{
	std::vector< std::string > result;
	// const 型不可使用 operator[] 因此需要强制转换
	auto& prev = const_cast<std::unordered_map< std::string, std::string >&> (previous);
	for (std::string current = second; current != ""; current = prev[current])
		result.push_back(current);

	std::reverse(std::begin(result), std::end(result));   // 顺序变为倒序
	return result;
}
/**
 * @description: 得到 first 到 second 之间的最短路径
 * @param {type} adjacentWords 图 first 起点 second 终点
 * @return: 路径
 */
std::vector< std::string > getPath(
	const std::unordered_map< std::string, std::vector< std::string > > & adjacentWords,
	const std::string & first, const std::string & second)
{
	return getChainFormPreviousMap(findChain(adjacentWords, first), second);
}
int main()
{
	graph< int > gh;
	gh.pushENode(1);
	gh.pushENode(2);
	gh.pushENode(3);
	gh.pushENode(4);
	gh.pushENode(5);
	gh.pushENode(6);
	gh.pushENode(7);

	gh.setEdge(1, 2, 2);
	gh.setEdge(1, 3, 4);
	gh.setEdge(1, 4, 1);

	gh.setEdge(2, 1, 2);
	gh.setEdge(2, 4, 3);
	gh.setEdge(2, 5, 10);

	gh.setEdge(3, 1, 4);
	gh.setEdge(3, 4, 2);
	gh.setEdge(3, 6, 5);

	gh.setEdge(4, 1, 1);
	gh.setEdge(4, 2, 3);
	gh.setEdge(4, 3, 2);
	gh.setEdge(4, 5, 7);
	gh.setEdge(4, 6, 8);
	gh.setEdge(4, 7, 4);

	gh.setEdge(5, 2, 10);
	gh.setEdge(5, 4, 7);
	gh.setEdge(5, 7, 6);

	gh.setEdge(6, 3, 5);
	gh.setEdge(6, 4, 8);
	gh.setEdge(6, 7, 1);

	gh.setEdge(7, 6, 1);
	gh.setEdge(7, 4, 4);
	gh.setEdge(7, 5, 6);

	// gh.topsort( );

	gh.prim( );
	gh.print( );
	return 0;
}