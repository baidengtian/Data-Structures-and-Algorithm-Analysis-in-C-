/*
 * @Author: lsyy
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-04-09 16:42:59
 * @LastEditors: Please set LastEditors
 * @Description: ��������
 * @FilePath: \insertion sort\Src\main.cpp
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
void insertionSort(std::vector<Comparable> & a )
{
    for( int i = 1; i < a.size( ); ++i )
    {
        Comparable tmp = a[ i ];
        int j;
        for( j = i; j > 0 && tmp < a[ j-1 ]; --j )
            a[ j ] = a[ j-1 ];
        a[ j ] = tmp;
    }
}

/**
 * @description: ���������㷨 ʱ�临�Ӷ�O(N^2)
 * @param {type} begin ��ʼλ�� end ��βλ�� lessThan �Ƚϴ�С�ĺ������� 
 * @return: null
 */
template < typename Iterator, typename Comparator >
void insertionSort( const Iterator & begin, const Iterator & end, Comparator lessThan )
{
    if( begin == end )
        return;
    Iterator j;
    for( Iterator it = begin + 1; it != end; ++it )
    {
        auto tmp = *it;
        for( j = it; j != begin && lessThan( tmp, *( j - 1 ) ); --j )
            *j = *( j - 1 );
        *j = tmp; 
    }
}

/**
 * @description: ���������㷨 ʱ�临�Ӷ�O(N^2)
 * @param {type} begin ��ʼλ�� end ��βλ��
 * @return: null
 */
template < typename Iterator >
void insertionSort( const Iterator & begin, const Iterator & end )
{
    insertionSort( begin, end, std::less<decltype(*begin)>{} );
}

class Comparator
{
public:
    bool operator ()( int & val1, int & val2 )
    {
        return val1 > val2;
    }
};

int main( )
{
    int a[] = {1,8,7,5,90,8,4,2,7,6};
    std::vector<int> iv(a,a+sizeof(a)/sizeof(int));
    insertionSort( iv.begin( ), iv.end( ) ,Comparator{ } );

    return 0;
}


