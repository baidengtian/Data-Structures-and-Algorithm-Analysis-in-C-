/*
 * @Author: lsyy
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-04-09 17:44:53
 * @LastEditors: Please set LastEditors
 * @Description: 堆排序
 * @FilePath: \insertion sort\Src\main.cpp
 */



#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>


/**
 * @description: 堆排序内部方法 获得左儿子
 * @param {type} i 堆中父节点下标  
 * @return: 返回左儿子下标
 */
inline int leftChild( int i )
{
    return 2 * i + 1;
}
/**
 * @description: 下滤
 * @param {type} a 排序数组 i 开始下滤的位置 n 是二叉堆的逻辑大小
 *                ( 因为每次要把删除的值由后向前插入到数组中 )
 * @return: null
 */
template < typename Comparable >
void percDown( std::vector<Comparable> & a, int i, int n )
{
    int child;
    Comparable tmp;
    for( tmp = std::move( a[ i ] ); leftChild( i ) < n; i = child )
    {
        child = leftChild( i );
        if( child != n - 1 && a[ child ] < a[ child + 1 ] ) // 寻找一个值大的儿子
            child ++;   
        if( tmp < a[ child ] )
            a[ i ] = std::move( a[ child ] );
        else
            break;
    }
    a[ i ] = std::move( tmp );
}
/**
 * @description: 堆排序算法 时间复杂度O(NlogN)
 * @param {type} a 排序数组  
 * @return: null
 */
template < typename Comparable >
void heapsort( std::vector<Comparable> & a )
{
    for( int i = a.size( ) / 2 - 1; i >= 0; --i )           // 构建堆
        percDown( a, i, a.size( ) );
    for( int j = a.size( ) - 1; j > 0; j-- )                // 删除最大元素
    {
        std::swap( a[ 0 ], a[ j ] );
        // 注意这里是交换完逻辑上的最后一个元素和第一个元素(最大值) 再下滤第一个元素的 
        percDown( a, 0, j );
    }
}
int main( )
{
    int a[] = {1,8,7,5,90,8,4,2,7,6};
    std::vector<int> iv(a,a+sizeof(a)/sizeof(int));
    heapsort( iv );
    return 0;
}


