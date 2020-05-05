/*
 * @Author: lsyy
 * @Date: 2020-02-26 10:22:04
 * @LastEditTime: 2020-02-26 10:31:23
 * @LastEditors: Please set LastEditors
 * @Description: ���������㷨
 * @FilePath: \quick select\Src\quicksort.cpp
 */

#include "quicksort.h"
/**
 * @description: ���������㷨 ʱ�临�Ӷ�O(N^2)
 * @param {type} a ��������  
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
 * @description: ���� left center �� right�������ֵ
 *               ����������������ŦԪ
 * @param {type} a ���������� left ����±� right �Ҷ��±�
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
 * @description: �������� ƽ��ʱ�临�Ӷ� O(NlogN) �O(N^2)
 * @param {type} a ���������� left ����±� right �Ҷ��±�
 * @return: null 
 */
template < typename Comparable >
void quicksort( std::vector<Comparable> & a, int left, int right )
{
    // ���� 10 �����ÿ������� ���� �ò�������
    if( left + 10 < right )
    {
        const Comparable & pivot = median3( a, left, right );
        // ��ʼ�ָ�
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
        // �ָ���ŦԪ
        std::swap( a[ i ], a[ right - 1 ] );
        quicksort( a, left, i - 1 );
        quicksort( a, i + 1, right );
    }
    else
		insertionSort( a, left, right );

}
/**
 * @description: �������� ��������
 * @param {type} a ����������
 * @return: null
 */
template < typename Comparable >
void quicksort( std::vector<Comparable> & a )
{
    quicksort( a, 0, a.size( ) - 1 );
}

