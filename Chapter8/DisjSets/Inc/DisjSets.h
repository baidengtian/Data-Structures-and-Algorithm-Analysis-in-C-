/*
 * @Author: lsyy
 * @Date: 2020-02-28 11:42:01
 * @LastEditTime: 2020-02-28 20:09:24
 * @LastEditors: Please set LastEditors
 * @Description: 不相交集类
 * @FilePath: \DisjSets\Inc\DisjSets.h
 */
#pragma 

#include <iostream>
#include <vector>

class DisjSets
{

public:
    explicit DisjSets( int numElements ) : s ( numElements - 1 )
    {
        for( int & elem : s )
            elem = -1;
    }
    // 任意合并两个不相交集合
    void unionSets( int root1, int root2 )
    {
        s[ root2 ] = root1;
    }
    // 按根深合并
    void unionSetsByHight( int root1, int root2 )
    {
        if( s[ root2 ] < s[ root1 ] )           // 如果 root2 比 root1深
            s[ root1 ] = root2;                 // 使 root2 为新的根
        else
        {
            if( s[ root1 ] == s[ root2 ] )      // 如果相同 , 则更新高度 
                --s[ root1 ];
            s[ root2 ] = root1;                 // 使 root1 为新根
        }
    }
    // 按树大小合并
    void unionSetsBySzie( int root1, int root2 )
    {
        if( s[ root2 ] < s[ root1 ] )           // 如果 root2 比 root1深
        {
            s[ root2 ] += s[ root1 ];
            s[ root1 ] = root2;                 // 使 root2 为新的根
        }           
        else
        {
            s[ root1 ] += s[ root2 ];
            s[ root2 ] = root1;                 // 使 root1 为新根      
        }
    }
    // 寻找 x 所在集合
    int find( int x )   const
    {
        if( s[ x ] < 0 )
            return x;
        else
            return find( s[ x ] );
    }
    // 寻找 x 所在集合 压缩路径
    int PathCompressionfind( int x )   
    {
        if( s[ x ] < 0 )
            return x;
        else
            return s[ x ] = find( s[ x ] );
    }
private:
    std::vector<int> s;
};

