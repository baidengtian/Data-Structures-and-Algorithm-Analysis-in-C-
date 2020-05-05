/*
 * @Author: your name
 * @Date: 2020-03-01 16:19:01
 * @LastEditTime: 2020-03-02 20:52:31
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
#include <climits>


template < typename Comparable >
class graph
{
public:
    struct graphNode
    {
        Comparable element;
        std::list< graphNode* > NextNodeList;
        
        // ������������
        int indegree;                           // ���
        int topNum;                             // ��������
        
        // ���ڹ����������
        int dist;                               // �� s ��ʼ������ľ���
        graphNode* path;                         // ·��
        bool known;                             // ��Ƕ����Ƿ񱻴���� �����Ϊ true   

        graphNode( Comparable val )
            : element { val }, topNum { 0 }, indegree{ 0 }, dist { 0 }, known { false }, path { nullptr }
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
            std::cout << node->dist << "        ";
        std::cout << std::endl;
        // for( auto node : Array )
        //     std::cout << node->topNum << "        ";
        // std::cout << std::endl;
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
    // ��Ȩ���·�� �����������
    void unweighted( graphNode* s )
    {
        std::queue< graphNode* > q;

        for( auto thisElement : Array )
            thisElement->dist = INT_MAX;
        
        s->dist = 0;
        q.push( s );

        while ( !q.empty( ) )
        {
            graphNode* node = q.front( );
            q.pop( );
            for( auto x : node->NextNodeList )
                if( x->dist == INT_MAX )
                {
                    x->dist = node->dist + 1;
                    x->path = node;
                    q.push( x );    
                }
        }

    }

    // �õ� from �� to �������������·��
    void getPath( graphNode* from, graphNode* to )
    {
        graphNode* tmp = to; 
        unweighted( from );
        getPath( tmp );
        // while( tmp != nullptr )
        // {
        //     std::cout << tmp->element;
        //     tmp = tmp -> path;
        // }
    }

private:
    void getPath( graphNode* to )
    {
        if( to->path != nullptr )
        {
            getPath( to->path );
            std::cout << " to ";
        }
        std::cout << to->element;
    }
    // �������
    void UpdataIndegree( ) 
    {
        for( auto thisElement : Array )
            for( auto node : thisElement->NextNodeList )
                ++( node->indegree );
    }
    std::vector< graphNode* > Array;
};