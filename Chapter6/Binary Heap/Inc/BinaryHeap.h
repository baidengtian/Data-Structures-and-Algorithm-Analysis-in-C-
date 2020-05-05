/*
 * @Author: your name
 * @Date: 2020-02-15 16:08:15
 * @LastEditTime: 2020-04-08 15:44:21
 * @LastEditors: Please set LastEditors
 * @Description: ������� ��С��
 * @FilePath: \Binary Heap\Inc\BinaryHeap.h
 */

#ifndef __BINARYHEAP_H
#define __BINARYHEAP_H

#include "dsexceptions.h"

#include <vector>
#include <iostream>
template < typename Comparable >

class BinaryHeap
{
public:
    explicit BinaryHeap( int capacity = 100 )
    {
        array.resize( capacity );
        currentSize = 0;
    }
    explicit BinaryHeap( const std::vector<Comparable> & items )
    : array( items.size( ) + 10 ), currentSize { items.size( ) }
    {
        for( int i = 0; i < items.size( ); ++i )
            array[ i + 1 ] = items[ i ];
        buildHeap( );
        // std::vector<Comparable> temp = items;
        // this->array = std::move( temp );
    }
    // �ж��Ƿ�Ϊ��
    bool isEmpty( ) const
    {
        return array.empty( );
    }
    // ����Сֵ
    const Comparable & findMin( )   const
    {
        if( !isEmpty() )
            return array[1];
        else
            return -1;
    }

    // ����Ԫ��
    void insert( const Comparable & x )
    {
        if( currentSize == array.size( ) - 1 )           // array[0]����ֵ ����Ҫ-1
            array.resize( 2 * array.size( ) );

        // ����
        int hole = ++currentSize;
        Comparable copy = x;

        array[0] = std::move( copy );                   // ���ڲ���ֵ�ȶ�������Ԫ��Сʱ����forѭ��
        for( ; x < array[ hole / 2 ]; hole /= 2 )       // ��Ϊ hole = 1ʱ array[hole/2] = array[0] = x ������ x < array[ hole / 2 ]
            array[ hole ] = std::move( array[ hole / 2 ] );
        array[ hole ] = std::move( array[0] );

    }
    // ɾ����Сֵ
    void deleteMin( )
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        array[1] = std::move( array[ currentSize-- ] );
        percolateDown( 1 );
    }
    void deleteMin( Comparable & minItem )
    {
        if( isEmpty( ) )
            throw UnderflowException( );
        minItem = std::move( array[1] );
        array[1] = std::move( array[ currentSize-- ] );
        percolateDown( 1 );
    }
    // ���
    void makeEmpty( )
    {
        array.erase(array.begin(),array.end());
    }
    // ��ӡ
    void print( )
    {
        for( int i = 1; i <= currentSize; i++ )
            std::cout << array[ i ] << std::endl;
        // for( auto x : array )
        //     std::cout << x << std::endl;
    }
private:
    int currentSize;                                    // ����Ԫ����
    std::vector<Comparable> array;                      // �ѵ�����
    void buildHeap( ){
        for( int i = currentSize / 2; i > 0; --i )
            percolateDown( i );
    }
    // ����
    void percolateDown( int hole )
    {
        int child;
        // ����������ұߵ�ֵ
        Comparable tmp = std::move( array[hole] );
    
        // hole * 2 <= currentSize �ж��ǲ�����Ҷ
        for( ; hole * 2 <= currentSize; hole = child )
        {
            child = hole * 2;
            // child != currentSize ��֤����ż����Ԫ��Ҳ�ܳɹ�
            // array[child] > array[child+1] ѡȡһ����С�Ķ���
            // child == currentSize �������ż����Ԫ��
            if( child != currentSize && array[child] > array[child+1] )
                child ++;
            if( tmp > array[ child ] )
                array[ hole ] = std::move( array[ child ] );
            else
                break;
        }
        array[ hole ] = std::move( tmp );

    }
};





#endif