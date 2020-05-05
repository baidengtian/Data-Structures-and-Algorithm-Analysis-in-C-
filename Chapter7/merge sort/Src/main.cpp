/*
 * @Author: lsyy
 * @Date: 2020-02-24 10:41:45
 * @LastEditTime: 2020-04-09 21:03:03
 * @LastEditors: Please set LastEditors
 * @Description: �鲢����
 * @FilePath: \merge sort\Src\main.cpp
 */



#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>


/**
 * @description: �ϲ�����
 * @param {type} a Ҫ�������� tmpArray ���ù鲢���������
 *               leftPos ǰ�벿����ʼԪ�ص��±� rightPos ��벿����ʼԪ�ص��±� 
 *               rightEnd ��벿��ĩβԪ�ص��±�
 * @return: null
 */
template < typename Comparable >
void merge( std::vector<Comparable> & a, std::vector<Comparable> & tmpArray,
            int leftPos, int rightPos, int rightEnd )
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // ��ѭ��
    while( leftPos <= leftEnd && rightPos <= rightEnd )
        if( a[ leftPos ] <= a[ rightPos ] )
            tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
        else
            tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    // ����ǰ�벿�ֵ�ʣ��Ԫ��
    while( leftPos <= leftEnd )
        tmpArray[ tmpPos++ ] = a[ leftPos++ ];
    while( rightPos <= rightEnd )
        tmpArray[ tmpPos++ ] = a[ rightPos++ ];

    // ��tmpArray���ƻ�ԭ����a
    for( int i = 0; i < numElements; ++i, --rightEnd )
        a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );

}
/**
 * @description: �����㷨 
 * @param {type} a Ҫ�������� tmpArray ���ù鲢���������
 *               left �����������Ԫ�ص��±� right ���������ұ�Ԫ�ص��±� 
 * @return: null
 */
template < typename Comparable >
void mergeSort( std::vector<Comparable> & a, std::vector<Comparable> & tmpArray,
                int left, int right )
{
    if( left < right )
    {
        int center = ( left + right ) / 2;
        // ��
        mergeSort( a, tmpArray, left, center );
        mergeSort( a, tmpArray, center + 1, right );
        // ��
        merge( a, tmpArray, left, center + 1, right );
    }
}

/**
 * @description: �鲢����
 * @param {type} a Ҫ��������
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


