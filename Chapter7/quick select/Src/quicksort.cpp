/*
 * @Author: lsyy
 * @Date: 2020-02-26 10:22:04
 * @LastEditTime: 2020-02-26 10:31:23
 * @LastEditors: Please set LastEditors
 * @Description: 快速排序算法
 * @FilePath: \quick select\Src\quicksort.cpp
 */

#include "quicksort.h"
/**
 * @description: 插入排序算法 时间复杂度O(N^2)
 * @param {type} a 排序数组  
 * @return: null
 */
template < typename Comparable >
void insertionSort(std::vector<Comparable> & a, int left, int right )
{
    for( int i = left; i <= right; ++i )
    {
        Comparable tmp = a[ i ];
        int j;
        for( j = i; j > 0 && tmp < a[ j-1 ]; --j )
            a[ j ] = a[ j-1 ];
        a[ j ] = tmp;
    }
}

/**
 * @description: 返回 left center 和 right三项的中值
 *               将它们排序并隐匿枢纽元
 * @param {type} a 待排序数组 left 左端下标 right 右端下标
 * @return: null
 */
template < typename Comparable >
const Comparable & median3( std::vector<Comparable> & a, int left, int right )
{
    int center = ( left + right ) / 2;
    if( a[ center ] < a[ left ] )
        std::swap( a[ center ], a[ left ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ right ], a[ left ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[right] );
    
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}
/**
 * @description: 快速排序 平均时间复杂度 O(NlogN) 最坏O(N^2)
 * @param {type} a 待排序数组 left 左端下标 right 右端下标
 * @return: null 
 */
template < typename Comparable >
void quicksort( std::vector<Comparable> & a, int left, int right )
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
        quicksort( a, left, i - 1 );
        quicksort( a, i + 1, right );
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
void quicksort( std::vector<Comparable> & a )
{
    quicksort( a, 0, a.size( ) - 1 );
}

