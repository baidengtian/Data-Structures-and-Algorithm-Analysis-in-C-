/*
 * @Author: lsyy
 * @Date: 2020-03-01 16:15:46
 * @LastEditTime: 2020-03-04 12:13:43
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
    // std::list < int > l;
    // l.push_back( 1 );
    graph< int > gh;

    // gh.pushENode( 1 );
    // gh.pushENode( 2 );
    // gh.pushENode( 3 );
    // gh.pushENode( 4 );
    // gh.pushENode( 5 );
    // gh.pushENode( 6 );
    // gh.pushENode( 7 );
    // gh.setEdge( 1, 2 );
    // gh.setEdge( 1, 4 );
    // gh.setEdge( 1, 3 );
    // gh.setEdge( 2, 4 );
    // gh.setEdge( 2, 5 );
    // gh.setEdge( 3, 6 );   
    // gh.setEdge( 4, 3 );
    // gh.setEdge( 4, 6 );
    // gh.setEdge( 4, 7 );    
    // gh.setEdge( 5, 4 );
    // gh.setEdge( 5, 7 );   
    // gh.setEdge( 7, 6 );

    gh.pushENode( 1 );
    gh.pushENode( 2 );
    gh.pushENode( 3 );
    gh.pushENode( 4 );
    gh.pushENode( 5 );
    gh.pushENode( 6 );
    gh.pushENode( 7 );

    gh.setEdge( 1, 2, 2 );
    gh.setEdge( 1, 4, 1 );

    gh.setEdge( 2, 4, 3 );
    gh.setEdge( 2, 5, 10 );

    gh.setEdge( 3, 1, 4 ); 
    gh.setEdge( 3, 6, 5 );   
    
    gh.setEdge( 4, 3, 2 );
    gh.setEdge( 4, 5, 2 );
    gh.setEdge( 4, 6, 8 );
    gh.setEdge( 4, 7, 4 );    

    gh.setEdge( 5, 7, 6 );   

    gh.setEdge( 7, 6, 1 );

    // gh.dijkstra( 1 );
    // gh.topsort( );
    // gh.print( );
    // gh.unweighted( 3 );
    // gh.print( );
    gh.getPath( gh.dijkstrasearch, 1, 6 );
    
    return 0;
}