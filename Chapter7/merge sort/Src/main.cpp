/*
 * @Author: lsyy
 * @Date: 2020-02-24 10:41:45
 * @LastEditTime: 2020-04-09 21:03:03
 * @LastEditors: Please set LastEditors
 * @Description: 归并排序
 * @FilePath: \merge sort\Src\main.cpp
 */



#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>


/**
 * @description: 合并数组
 * @param {type} a 要排序数组 tmpArray 放置归并结果的数组
 *               leftPos 前半部分起始元素的下标 rightPos 后半部分起始元素的下标 
 *               rightEnd 后半部分末尾元素的下标
 * @return: null
 */
template < typename Comparable >
void merge( std::vector<Comparable> & a, std::vector<Comparable> & tmpArray,
            int leftPos, int rightPos, int rightEnd )
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // 主循环
    while( leftPos <= leftEnd && rightPos <= rightEnd )
        if( a[ leftPos ] <= a[ rightPos ] )
            tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
        else
            tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    // 复制前半部分的剩余元素
    while( leftPos <= leftEnd )
        tmpArray[ tmpPos++ ] = a[ leftPos++ ];
    while( rightPos <= rightEnd )
        tmpArray[ tmpPos++ ] = a[ rightPos++ ];

    // 将tmpArray复制回原数组a
    for( int i = 0; i < numElements; ++i, --rightEnd )
        a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );

}
/**
 * @description: 分治算法 
 * @param {type} a 要排序数组 tmpArray 放置归并结果的数组
 *               left 子数组最左边元素的下标 right 子数组最右边元素的下标 
 * @return: null
 */
template < typename Comparable >
void mergeSort( std::vector<Comparable> & a, std::vector<Comparable> & tmpArray,
                int left, int right )
{
    if( left < right )
    {
        int center = ( left + right ) / 2;
        // 分
        mergeSort( a, tmpArray, left, center );
        mergeSort( a, tmpArray, center + 1, right );
        // 治
        merge( a, tmpArray, left, center + 1, right );
    }
}

/**
 * @description: 归并排序
 * @param {type} a 要排序数组
 * @return: null
 */
template < typename Comparable >
void mergeSort( std::vector<Comparable> & a )
{
    std::vector< Comparable > tmpArray( a.size( ) );
    mergeSort( a, tmpArray, 0, a.size( ) - 1 );
}

int main( )
{
    int a[] = {1,8,7,5,90,8,4,2,7,6};
    std::vector<int> iv(a,a+sizeof(a)/sizeof(int));

    mergeSort( iv );

    return 0;
}


