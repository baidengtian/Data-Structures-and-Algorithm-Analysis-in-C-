/*
 * @Author: your name
 * @Date: 2020-03-01 16:19:01
 * @LastEditTime: 2020-03-01 21:45:23
 * @LastEditors: Please set LastEditors
 * @Description: ͼӦ��֮��������
 * @FilePath: \topsort\Inc\graph.h
 */
#pragma
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include "dsexceptions.h"



template < typename Comparable >
class graph
{
public:
    struct graphNode
    {
        Comparable element;
        std::list< graphNode* > NextNodeList;
        int indegree;                       // ���
        int topNum;
        graphNode( Comparable val )
            : element { val }, topNum { 0 }, indegree{ 0 }
        {

        }
        void setNextNode( graphNode* pNode )
        {
            NextNodeList.push_back( pNode );
        }
    };   
    graph( )
    {

    }
    // ѹ��ڵ�
    void pushNode( graphNode* node )
    {
        Array.push_back( node );
    }

    void print( )
    {
        for( auto node : Array )
            std::cout << node->topNum << "        ";
        std::cout << std::endl;
    }
    // ��������
    void topsort( )
    {
        UpdataIndegree( );
        std::queue< graphNode* > q;
        int count = 0;

        for( auto node : Array )
            if( node->indegree == 0 )
                q.push( node );

        while ( !q.empty( ) )
        {
            graphNode* node = q.front( );
            q.pop( );
            // std::cout << node -> element << "           ";
            node->topNum = ++count;
            for( auto x : node->NextNodeList )
                if( --( x->indegree ) == 0 )
                {
                    q.push( x );
                    // std::cout << x -> element << "           ";
                }
        }
        if( count != Array.size( ) )
            throw CycleFoundException { };
    }
private:
    // �������
    void UpdataIndegree( ) 
    {
        for( auto thisElement : Array )
            for( auto node : thisElement->NextNodeList )
                ++( node->indegree );
    }
    std::vector< graphNode* > Array;
};