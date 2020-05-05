/*
 * @Author: your name
 * @Date: 2020-02-15 16:08:15
 * @LastEditTime: 2020-04-08 15:44:21
 * @LastEditors: Please set LastEditors
 * @Description: 二叉堆类 最小堆
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
    // 判断是否为空
    bool isEmpty( ) const
    {
        return array.empty( );
    }
    // 找最小值
    const Comparable & findMin( )   const
    {
        if( !isEmpty() )
            return array[1];
        else
            return -1;
    }

    // 插入元素
    void insert( const Comparable & x )
    {
        if( currentSize == array.size( ) - 1 )           // array[0]不存值 所以要-1
            array.resize( 2 * array.size( ) );

        // 上滤
        int hole = ++currentSize;
        Comparable copy = x;

        array[0] = std::move( copy );                   // 用于插入值比堆中所有元素小时结束for循环
        for( ; x < array[ hole / 2 ]; hole /= 2 )       // 因为 hole = 1时 array[hole/2] = array[0] = x 不满足 x < array[ hole / 2 ]
            array[ hole ] = std::move( array[ hole / 2 ] );
        array[ hole ] = std::move( array[0] );

    }
    // 删除最小值
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
    // 清空
    void makeEmpty( )
    {
        array.erase(array.begin(),array.end());
    }
    // 打印
    void print( )
    {
        for( int i = 1; i <= currentSize; i++ )
            std::cout << array[ i ] << std::endl;
        // for( auto x : array )
        //     std::cout << x << std::endl;
    }
private:
    int currentSize;                                    // 堆中元素树
    std::vector<Comparable> array;                      // 堆的数组
    void buildHeap( ){
        for( int i = currentSize / 2; i > 0; --i )
            percolateDown( i );
    }
    // 下滤
    void percolateDown( int hole )
    {
        int child;
        // 树最低曾最右边的值
        Comparable tmp = std::move( array[hole] );
    
        // hole * 2 <= currentSize 判断是不是树叶
        for( ; hole * 2 <= currentSize; hole = child )
        {
            child = hole * 2;
            // child != currentSize 保证堆中偶数个元素也能成功
            // array[child] > array[child+1] 选取一个较小的儿子
            // child == currentSize 二叉堆有偶数个元素
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