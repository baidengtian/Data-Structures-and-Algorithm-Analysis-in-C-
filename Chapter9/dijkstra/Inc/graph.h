/*
 * @Author: your name
 * @Date: 2020-03-01 16:19:01
 * @LastEditTime: 2020-03-04 16:17:37
 * @LastEditors: Please set LastEditors
 * @Description: 图应用之拓扑排序
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
    
    graph( int vnum, int ednum )
        : vexnum { vnum }, edgnum { ednum }
    {

    }
    graph( )
        : vexnum { 0 }, edgnum { 0 }
    {

    }
    // 放入顶点
    void pushENode( Comparable data )
    {
        VNode* pNode = new VNode{ data };
        vexs.push_back( *pNode );
        delete pNode;
    }
    // 设置边 vdata 顶点 edata 邻接点 weight 权重
    void setEdge( Comparable vdata, Comparable edata, int weight = 1 )
    {
        typename VNode::ENode* pNode = new typename VNode::ENode { get_position( edata ), weight };
        get_position( vdata ) -> medges.push_back( *pNode );
        delete pNode;
    }
    // 拓扑排序
    void topsort( )
    {
        int counter = 0;
        updataIndegree( );
        std::queue< Iterator > q;
        for( auto it = vexs.begin( ); it != vexs.end( ); ++it )
            if( it->mindegree == 0 )
                q.push( it );                       // 入队
            
        while ( !q.empty( ) )
        {
            Iterator v = q.front( );
            q.pop( );                               // 出队
            v->mtopNum = ++counter;
            for( auto & w : v->medges )
                if( --w.mit->mindegree == 0 )
                    q.push( w.mit );                // 入队
        }
        
        if( counter != vexs.size( ) )
            throw CycleFoundException{ };
    }
    
    // 广度优先搜索
    void unweighted( Comparable s )
    {
        std::queue< Iterator > q;
        Iterator it = get_position( s );
        it->dist = 0;
        q.push( it );
        while( !q.empty( ) )
        {
            Iterator v = q.front( );
            q.pop( );
            for( auto w : v->medges )
                if( w.mit->dist == INT_MAX )
                {
                    w.mit->dist = v->dist + 1;
                    w.mit->path = v;
                    q.push( w.mit );
                }
        }
    }
    enum option{ unweightedsearch, dijkstrasearch };
    // 得到from到to之间的最短路径
    void getPath( int searchoption, Comparable from, Comparable to )
    {
        switch ( searchoption )
        {
        case graph::unweightedsearch :
            unweighted( from );
            break;
        case graph::dijkstrasearch :
            dijkstra( from );
            break;
        default:
            break;
        }
        // unweighted( from );
        // dijkstra( from );
        getPath( get_position( from ), get_position( to ) );     
    }
    // 最短路径迪杰斯特拉算法 
    void dijkstra( Comparable s )
    {
        auto it = get_position( s ); 
        it->dist = 0;
        std::queue< Iterator > q;
        q.push( it );
        while( !q.empty( ) )
        {
            Iterator v = q.front( );
            q.pop( );
            for( auto w : v->medges )     
                if( v->dist + w.mweight < w.mit->dist )
                {
                    w.mit->dist = v->dist + w.mweight;  
                    w.mit->path = v;
                    q.push( w.mit );
                }                        
        }      
    }
    // 具有负边的图
    void weightedNegative( Comparable s )
    {
        auto it = get_position( s ); 
        it->dist = 0;
        it->inqueue = true;
        std::queue< Iterator > q;
        q.push( it );
        while( !q.empty( ) )
        {
            Iterator v = q.front( );
            q.pop( );
            v->inqueue = false;
            for( auto w : v->medges )     
                if( v->dist + w.mweight < w.mit->dist )
                {
                    w.mit->dist = v->dist + w.mweight;  
                    w.mit->path = v;
                    if( !w.mit->inqueue )
                    {
                        w.mit->inqueue = true;                      // 标记顶点已进入队列
                        q.push( w.mit );
                    }
                        
                }                        
        }   
    }
    void print( )
    {
        // for( auto node : vexs )
        //     std::cout << node.mtopNum << "  ";
        // std::cout << std::endl;
        for( auto node : vexs )
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
            typename std::vector<VNode>::iterator mit;              // 该边的顶点的位置                                
            int mweight;                                            // 该边的权重
            ENode( typename std::vector<VNode>::iterator pvex, int weight )
                : mit { pvex }, mweight { weight }
            {

            }
        }; 
        Comparable mdata;                                           // 顶点信息
        int mindegree;                                              // 入度
        int mtopNum;                                                // 拓扑号
        
        int dist;                                                   // 距离
        typename std::vector<VNode>::iterator path;                 // 路径

        bool inqueue;                                               // 标记顶点是否已在队列中


        std::list< ENode >  medges;                                 // 该顶点的邻接边的链表  
        VNode( Comparable data )
            : mdata { data }, mindegree { 0 }, mtopNum { 0 }, 
              dist { INT_MAX }, path { nullptr } ,inqueue { false }
        {

        }
    };
    typedef typename std::vector<VNode>::iterator Iterator;
    // 返回节点所在位置
    Iterator get_position( Comparable element )  
    {
        for(  auto it = vexs.begin( ); it != vexs.end( ); ++it )
            if( it->mdata == element )
                return it;
        throw ArrayIndexOutOfBoundsException { };
    }
    // 更新入度
    void updataIndegree( )
    {
        for( auto node : vexs )
            for( auto x : node.medges )
                ++x.mit->mindegree;
    }
    // 得到 from 到 to 之间路径内部方法
    void getPath( Iterator from,
                  Iterator to )
    {
        if( to != from )
        {
            getPath( from, to->path );
            std::cout << "-->>";
        }
            
        std::cout << to->mdata;      
    }
    int vexnum;                         // 图的顶点数目
    int edgnum;                         // 图的边的数目
    std::vector< VNode > vexs;          // 图顶点储存容器

};
