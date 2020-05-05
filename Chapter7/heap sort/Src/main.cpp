/*
 * @Author: lsyy
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-04-09 17:44:53
 * @LastEditors: Please set LastEditors
 * @Description: ������
 * @FilePath: \insertion sort\Src\main.cpp
 */



#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>


/**
 * @description: �������ڲ����� ��������
 * @param {type} i ���и��ڵ��±�  
 * @return: ����������±�
 */
inline int leftChild( int i )
{
    return 2 * i + 1;
}
/**
 * @description: ����
 * @param {type} a �������� i ��ʼ���˵�λ�� n �Ƕ���ѵ��߼���С
 *                ( ��Ϊÿ��Ҫ��ɾ����ֵ�ɺ���ǰ���뵽������ )
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
        if( child != n - 1 && a[ child ] < a[ child + 1 ] ) // Ѱ��һ��ֵ��Ķ���
            child ++;   
        if( tmp < a[ child ] )
            a[ i ] = std::move( a[ child ] );
        else
            break;
    }
    a[ i ] = std::move( tmp );
}
/**
 * @description: �������㷨 ʱ�临�Ӷ�O(NlogN)
 * @param {type} a ��������  
 * @return: null
 */
template < typename Comparable >
void heapsort( std::vector<Comparable> & a )
{
    for( int i = a.size( ) / 2 - 1; i >= 0; --i )           // ������
        percDown( a, i, a.size( ) );
    for( int j = a.size( ) - 1; j > 0; j-- )                // ɾ�����Ԫ��
    {
        std::swap( a[ 0 ], a[ j ] );
        // ע�������ǽ������߼��ϵ����һ��Ԫ�غ͵�һ��Ԫ��(���ֵ) �����˵�һ��Ԫ�ص� 
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


