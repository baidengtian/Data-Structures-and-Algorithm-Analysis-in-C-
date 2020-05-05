/*
 * @Author: lsyy
 * @Date: 2020-02-24 10:41:45
 * @LastEditTime: 2020-04-10 17:45:00
 * @LastEditors: Please set LastEditors
 * @Description: 快速选择
 * @FilePath: \quick select\Src\main.cpp
 */

#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>
#include "dsexceptions.h"
#include "quicksort.cpp"        

/**
 * @description: 快速排序 平均时间复杂度 O(NlogN) 最坏O(N^2)
 * @param {type} a 待排序数组 left 左端下标 right 右端下标
 * @return: null 
 */
template < typename Comparable >
void quickSelect( std::vector<Comparable> & a, int left, int right, int k )
{
    // 超过 10 个数用快速排序 否则 用插入排序
    if( left + 10 < right )
    {
        const Comparable & pivot = median3( a, left, right );
        // 开始分割
        int i = left, j = right - 1;
        for( ; ; )
        {
            while( a[ ++i ] < pivot ) { }
            while( a[ --j ] > pivot ) { }
            if( i < j )
                std::swap( a[ i ], a[ j ] );
            else
                break;
        }
        // 恢复枢纽元
        std::swap( a[ i ], a[ right - 1 ] );

        if( k <= i )
            quickSelect( a, left, i-1, k );
        else
            quickSelect( a, i + 1, right, k );
    }
    else
        insertionSort( a, left, right );

}
/**
 * @description: 快速排序 驱动程序
 * @param {type} a 待排序数组
 * @return: null
 */
template < typename Comparable >
Comparable quickSelect( std::vector<Comparable> & a, int k )
{
    if( k > 0 )
    {
        quickSelect( a, 0, a.size( ) - 1, k );
        return a[ k-1 ];
    }
    else
        throw UnderflowException{ };

}
// // 第 k 个最大值
// Comparable quickSelect( std::vector<Comparable> & a, int k )
// {
//     int pos = a.size( ) - k + 1;
//     if( pos > 0 )
//     {
//         quickSelect( a, 0, a.size( ) - 1, pos );
//         return a[ pos - 1 ];
//     }
//     else
//         throw UnderflowException{ };

// }

int main( )
{
    int a[] = {1,8,7,5,90,8,4,2,7,6,10,7,555,8,77,66,44,33,111,5555,66,666,7894,85,58,33,11,12
                ,1,8,7,5,90,8,4,2,7,6,10,7,555,8,77,66,44,33,111,5555,66,666,7894,85,58,33,11,12};
    std::vector<int> iv(a,a+sizeof(a)/sizeof(int));
    
    int val = quickSelect( iv, 2 );

    // quicksort( iv );
    // TestPrint( );
    return 0;
}


