/*
 * @Author: lsyy
 * @Date: 2020-02-24 10:41:45
 * @LastEditTime: 2020-04-10 16:54:52
 * @LastEditors: Please set LastEditors
 * @Description: ��������
 * @FilePath: \quick sort\Src\main.cpp
 */


#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>
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
    // ���С���� : ���� 10 �����ÿ������� ���� �ò�������
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


template < typename Comparable >
void SORT( std::vector< Comparable > &items ){
    if( items.size( ) > 1 ){
        std::vector< Comparable > smaller;
        std::vector< Comparable > same;
        std::vector< Comparable > larger;

        auto chosenItem = items[ items.size( ) / 2 ];

        for( auto &i : items ){
            if( i < chosenItem )
                smaller.push_back( i );
            else if( i > chosenItem )
                larger.push_back( i );
            else
                same.push_back( i );
        }

        SORT( smaller );
        SORT( larger );

        std::move( smaller.begin( ), smaller.end( ), std::begin( items ) );
        std::move( same.begin( ), same.end( ), std::begin( items ) + smaller.size( ) );
        std::move( larger.begin( ), larger.end( ), std::end( items ) - larger.size( ) );
    }
}


int main( )
{
    int a[] = {1,8,7,5,90,8,4,2,7,6,10,7,555,8,77,66,44,33,111,5555,66,666,7894,85,58,33,11,12
                ,1,8,7,5,90,8,4,2,7,6,10,7,555,8,77,66,44,33,111,5555,66,666,7894,85,58,33,11,12};
    std::vector<int> iv(a,a+sizeof(a)/sizeof(int));

    quicksort( iv );
    // SORT( iv );
    
    return 0;
}


 