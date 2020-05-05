/*
 * @Author: your name
 * @Date: 2020-02-15 16:08:15
 * @LastEditTime: 2020-02-19 20:22:38
 * @LastEditors: Please set LastEditors
 * @Description: 左式堆
 * @FilePath: \LeftistHeap\Inc\LeftistHeap.h
 */

#ifndef __LEFTISTHEAD_H
#define __LEFTISTHEAD_H


#include <vector>
#include <iostream>
#include "dsexceptions.h"

template < typename Comparable >
class LeftistHeap
{
public:
    LeftistHeap( ) : root{ nullptr }
    {

    }
    LeftistHeap( const LeftistHeap & rhs ): root( nullptr )
    {
        this->root = clone( rhs.root );
    }
    ~LeftistHeap( )
    {
        makeEmpty( );
    }
    // 深拷贝
    LeftistHeap & operator = ( const LeftistHeap & rhs )
    {
        LeftistHeap copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    // 移动
    LeftistHeap & operator = ( LeftistHeap && rhs )
    {
        std::swap( root, rhs.root );
        
        return *this;
    }

    // 判断左式堆是否为空
    bool isEmpty( ) const
    {
        return root == nullptr;
    }
    // 寻找最小值
    const Comparable & findMin( )   const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return root->element;
    }
    // 插入节点 x
    void insert( const Comparable & x )
    {
        root = merge( new LeftistNode{ x }, root );
    }
    // 删除最小项
    void deleteMin( )
    {
        if( isEmpty( ) )
           throw UnderflowException{ };
        
        LeftistNode* oldRoot = root;
        root = merge( root->left, root->right );
        delete oldRoot;
    }
    // 删除最小值
    void deleteMin( Comparable & minItem )
    {
        minItem = findMin( );
        deleteMin( );
    }
    void makeEmpty( )
    {
        reclaimMemory( root );
        root = nullptr;
    }
    // 将 rhs 合并到优先队列
    void merge( LeftistHeap & rhs )
    {
        if( this == &rhs )                      // rhs 必须不同于 this
            return;
        root = merge( root, rhs.root );
        rhs.root = nullptr;
    }
    void print( )   const{
        print( root );
    }

private:
    struct LeftistNode
    {
        Comparable element;
        LeftistNode* left;
        LeftistNode* right;
        int npl;                // 零路径长
        LeftistNode( const Comparable & e, LeftistNode* lt = nullptr, 
                    LeftistNode* rt = nullptr, int np = 0 )
        : element{ e }, left{ lt }, right{ rt }, npl{ np }
        {

        }

    };

    LeftistNode* root;          // 根节点
    // 合并两个根
    LeftistNode* merge( LeftistNode* h1, LeftistNode* h2 )
    {
        if( h1 == nullptr )
            return h2;
        if( h2 == nullptr )
            return h1;
        if( h1->element < h2->element )
            return merge1( h1, h2 );
        else
            return merge1( h2, h1 );
    }
    // 合并两个左式树 h1 < h2
    LeftistNode* merge1( LeftistNode* h1, LeftistNode* h2 )
    {
        // 单节点
        // 左式堆如果 h->left = nullptr, 则 h->right = nullptr
        if( h1->left == nullptr )           
            h1->left = h2;
        else
        {
            // 递归合并根节点小的右子树与根节点大的树
            h1->right = merge( h1->right, h2 );        
            // 左子树的零路径长小于右子树的零路径长时交换左右子树
            if( h1->left->npl < h1->right->npl )
                swapChildren( h1 );
            // 根节点的零路径长 = 右子树零路径长 + 1 
            h1->npl = h1->right->npl + 1; 
        }

        return h1;
    }
    // 交换一个节点的左右儿子
    void swapChildren( LeftistNode* t )
    {
        LeftistNode* tempNode = t->left; 
        t->left = t->right;
        t->right = tempNode;
    }
    // 清空某子树
    void reclaimMemory( LeftistNode* t )
    {
        if( t != nullptr )
        {
            reclaimMemory( t->left );
            reclaimMemory( t->right );
            delete t;
        }
    }
    // 克隆节点
    LeftistNode* clone( LeftistNode* t )    const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new LeftistNode{ t->element, clone( t->left ), clone( t->right ), t->npl };
        
    }
    void print( LeftistNode *t )   const{
        if( t != nullptr ){
            print( t->left );
            std::cout << t->element <<" ";
            print( t->right );
        }
    }
};





#endif