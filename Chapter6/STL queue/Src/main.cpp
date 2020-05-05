/*
 * @Author: lsyy
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-04-09 15:28:35
 * @LastEditors: Please set LastEditors
 * @Description: 二项队列测试函数
 * @FilePath: \BinomialQueue\Src\main.cpp
 */



#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

template < typename PriorityQueue >
void dumpContents( const std::string & msg, PriorityQueue & pq )
{
    std::cout << msg << ":" << std::endl;
    while ( !pq.empty( ) )
    {
        std::cout << pq.top( ) << std::endl;
        pq.pop( );
    }
    
}

 
