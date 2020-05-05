/*
 * @Author: your name
 * @Date: 2020-02-15 16:08:15
 * @LastEditTime: 2020-04-09 11:29:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \BinomialQueue\Inc\BinomialQueue.h
 */


#ifndef __BINOMIALQUEUE_H
#define __BINOMIALQUEUE_H


#include <vector>
#include <iostream>
#include "dsexceptions.h"
#include <algorithm>

template < typename Comparable >

class BinomialQueue
{
public:
    BinomialQueue( ) : theTrees( 1 )
    {
        for( auto & root : theTrees )
            root = nullptr;
        currentSize = 0;
    }
    BinomialQueue( const Comparable & item ) : theTrees( 1 ), currentSize{ 1 }
    {
        theTrees[ 0 ] = new BinomialNode{ item, nullptr, nullptr };
    }
    // 拷贝构造
    BinomialQueue( const BinomialQueue & rhs )
    : theTrees( rhs.theTrees.size( ) ),currentSize{ rhs.currentSize }
    {
        for( int i = 0; i < rhs.theTrees.size( ); ++i )
           this->theTrees[ i ] = clone(rhs.theTrees[ i ]);
    }
    ~BinomialQueue( )
    {
        makeEmpty( );
    }
    // 深拷贝
    BinomialQueue & operator = ( const BinomialQueue & rhs )
    {
        // currentSize = rhs.currentSize;
        // for( int i = 0; i < rhs.theTrees.size( ); ++i )
        //     this->theTrees.push_back(clone(rhs.theTrees[ i ]));
        // return *this;
        BinomialQueue copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    // 移动
    BinomialQueue & operator = ( BinomialQueue && rhs )
    {
        std::swap( currentSize, rhs.currentSize );
        std::swap( theTrees, rhs.theTrees );      
        return *this;
    }

    // 判断是否为空
    bool isEmpty( )
    {
        return currentSize == 0;
    }
    // 寻找最小值
    const Comparable & findMin( )   const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return theTrees[ findMinIndex( ) ]->element;
    }
    // 插入元素 O(1)
    void insert( const Comparable & x )
    {
        BinomialQueue copy{ x };
        merge( copy );
    }
    // 删除最小值 O(log N)
    void deleteMin( )
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        int minIndex = findMinIndex( );

        BinomialNode* oldRoot = theTrees[ minIndex ];
        BinomialNode* deletedTree = oldRoot->leftChild;
        delete oldRoot;

        // 构建 H2
        BinomialQueue deletedQueue;
        deletedQueue.theTrees.resize( minIndex + 1 );
        deletedQueue.currentSize = ( 1 << minIndex ) - 1;
        for( int j = minIndex - 1; j >= 0; --j )
        {
            deletedQueue.theTrees[ j ] = deletedTree;
            deletedTree = deletedTree->nextSilbling;
            deletedQueue.theTrees[ j ]->nextSilbling = nullptr;
        }
        // 构建 H1
        theTrees[ minIndex ] = nullptr;
        currentSize -= deletedQueue.currentSize + 1;

        merge( deletedQueue ); 
    }
    // 删除最小值 O(log N)
    void deleteMin( Comparable & minItem )
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        int minIndex = findMinIndex( );
        minItem = theTrees[ minIndex ]->element;
        deleteMin( );
    }
    // 清空
    void makeEmpty( )
    {
        for( auto & root : theTrees )
            if( root != nullptr )
                makeEmpty( root );
        currentSize = 0;
    }

    // 合并两个二项队列  O(log N)
    void merge( BinomialQueue & rhs )
    {
        if( this == &rhs )
            return;    
        // 合并的两个队列 : this 树大于 rhs 树
        if( theTrees.size( ) < rhs.theTrees.size( ) ){   
            rhs.merge( *this );
            std::swap( this->theTrees, rhs.theTrees );
        }
        // 合并的两个队列 : this 树小于 rhs 树
        else{
            currentSize += rhs.currentSize;

            if( currentSize > capacity( ) )                         // 合并后的项数大于容量 扩展 vector 容器
            {
                int oldNumTrees = theTrees.size( );
                int newNumTrees = std::max( theTrees.size( ), rhs.theTrees.size( ) ) + 1;
                theTrees.resize( newNumTrees );
                for( int i = oldNumTrees; i < newNumTrees; ++i )    // 清空扩容的那部分
                    theTrees[ i ] = nullptr;
            }

            BinomialNode* carry = nullptr;                          // 上一步合并得来的树

            for( int i = 0, j = 1; j <= currentSize; ++i, j *= 2 )
            {
                BinomialNode* t1 = theTrees[ i ];
                BinomialNode* t2 = i < rhs.theTrees.size( ) ? rhs.theTrees[ i ] : nullptr;

                int whichCase = t1 == nullptr ? 0 : 1;              // t1是否为空
                whichCase += t2 == nullptr ? 0 : 2;                 // t2是否为空
                whichCase += carry == nullptr ? 0 : 4;              // 上一次的carry是否为空

                switch ( whichCase )
                {
                case 0: 
                case 1:
                    break;
                case 2:
                    theTrees[ i ] = t2;
                    rhs.theTrees[ i ] = nullptr;
                    break;
                case 4:
                    theTrees[ i ] = carry;
                    carry = nullptr;
                    break;
                case 3:
                    carry = combineTrees( t1, t2 );
                    theTrees[ i ] = rhs.theTrees[ i ] = nullptr;
                    break;
                case 5:
                    carry = combineTrees( t1, carry );
                    theTrees[ i ] = nullptr;
                    break;
                case 6:
                    carry = combineTrees( t2, carry );
                    rhs.theTrees[ i ] = nullptr;
                    break;
                case 7:
                    theTrees[ i ] = carry;
                    carry = combineTrees( t1, t2 );
                    rhs.theTrees[ i ] = nullptr;
                    break;
                default:
                    break;
                }
            }
        }
        
        for( auto & root : rhs.theTrees )                       // 清空被合并的二项队列
            root = nullptr;
        rhs.currentSize = 0;
    }

    int size( ) const{
        return theTrees.size( );
    }
private:
    struct BinomialNode
    {
        Comparable element;
        BinomialNode* leftChild;
        BinomialNode* nextSibling;
        BinomialNode( const Comparable & e, BinomialNode* lt, BinomialNode* rt )
        : element{ e }, leftChild{ lt }, nextSibling{ rt } 
        {

        }
    };
    const static int DEFAULT_TREES = 1;
    
    std::vector< BinomialNode* > theTrees;                      // 树根组成的数组
    int currentSize;                                            // 优先队列中的项数 元素个数

    // 寻找最小项的树的下标 O(N)
    int findMinIndex( ) const
    {
        int i;
        int minIndex;
        // 忽略前 i 个为空的项
        for( i = 0; theTrees[ i ] == nullptr; ++i )
            ;
        for( minIndex = i; i < theTrees.size( ); ++i )
            if( theTrees[ i ] != nullptr &&
                theTrees[ i ]->element < theTrees[ minIndex ]->element )
                minIndex = i;
        
        return minIndex;
    }
    // 二项队列容量
    int capacity( ) const
    {
        return ( 1 << theTrees.size( ) ) - 1; 
    } 
    // 合并两个子树 根节点小的一个子树的根做合并后树的根 
    BinomialNode* combineTrees( BinomialNode* t1, BinomialNode* t2 )
    {
        if( t2->element < t1->element )
            return combineTrees( t2, t1 );
        t2->nextSibling = t1->leftChild; 
        t1->leftChild = t2;
        return t1;
    }
    // 清空节点
    void makeEmpty( BinomialNode* & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->leftChild );
            makeEmpty( t->nextSibling );
            delete t;
            t = nullptr;
        }
    }
    // 克隆节点
    BinomialNode* clone( BinomialNode* t )  const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new BinomialNode{ t->element, clone( t->leftChild ), clone( t->nextSibling ) };

    }
};




#endif