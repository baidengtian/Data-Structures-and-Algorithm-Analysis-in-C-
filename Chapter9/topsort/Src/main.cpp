/*
 * @Author: lsyy
 * @Date: 2020-03-01 16:15:46
 * @LastEditTime: 2020-03-01 21:53:46
 * @LastEditors: Please set LastEditors
 * @Description: Õÿ∆À≈≈–Ú
 * @FilePath: \topsort\Src\main.cpp
 */
#include <iostream>
#include "graph.h"
#include <list>
#include <queue>

int main( )
{
    // std::queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // int num = q.back( );
    graph<int> gh;
    graph<int>::graphNode node1( 1 );
    graph<int>::graphNode node2( 2 );
    graph<int>::graphNode node3( 3 );
    graph<int>::graphNode node4( 4 );
    graph<int>::graphNode node5( 5 );
    graph<int>::graphNode node6( 6 );
    graph<int>::graphNode node7( 7 );
    
    node1.setNextNode( &node2 );
    node1.setNextNode( &node3 );
    node1.setNextNode( &node4 );

    node2.setNextNode( &node4 );
    node2.setNextNode( &node5 );

    node3.setNextNode( &node6 );

    node4.setNextNode( &node3 );
    node4.setNextNode( &node6 );
    node4.setNextNode( &node7 );

    node5.setNextNode( &node4 );
    node5.setNextNode( &node7 );

    node7.setNextNode( &node6 );

    gh.pushNode( &node1 );
    gh.pushNode( &node2 );
    gh.pushNode( &node3 );
    gh.pushNode( &node4 );
    gh.pushNode( &node5 );
    gh.pushNode( &node6 );
    gh.pushNode( &node7 );

    // graph<int> gh;
    // graph<int>::graphNode node1( 1 );
    // graph<int>::graphNode node2( 2 );
    // graph<int>::graphNode node3( 3 );
    // graph<int>::graphNode node4( 4 );
    // graph<int>::graphNode node5( 5 );
    // graph<int>::graphNode node6( 6 );
    // graph<int>::graphNode node7( 7 );
    // graph<int>::graphNode node9( 9 );

    // node1.setNextNode( &node3 );

    // node2.setNextNode( &node4 );
    // node2.setNextNode( &node6 );

    // node3.setNextNode( &node5 );

    // node4.setNextNode( &node5 );
    // node4.setNextNode( &node6 );

    // node5.setNextNode( &node7 );

    // node6.setNextNode( &node9 );

    // node7.setNextNode( &node9 );


    // gh.pushNode( &node1 );
    // gh.pushNode( &node2 );
    // gh.pushNode( &node3 );
    // gh.pushNode( &node4 );
    // gh.pushNode( &node5 );
    // gh.pushNode( &node6 );
    // gh.pushNode( &node7 );
    // gh.pushNode( &node9 );
    
    gh.topsort( );
    gh.print( );
    return 0;
}