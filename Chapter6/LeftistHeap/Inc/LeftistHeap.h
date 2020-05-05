/*
 * @Author: your name
 * @Date: 2020-02-15 16:08:15
 * @LastEditTime: 2020-02-19 20:22:38
 * @LastEditors: Please set LastEditors
 * @Description: ��ʽ��
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
    // ���
    LeftistHeap & operator = ( const LeftistHeap & rhs )
    {
        LeftistHeap copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    // �ƶ�
    LeftistHeap & operator = ( LeftistHeap && rhs )
    {
        std::swap( root, rhs.root );
        
        return *this;
    }

    // �ж���ʽ���Ƿ�Ϊ��
    bool isEmpty( ) const
    {
        return root == nullptr;
    }
    // Ѱ����Сֵ
    const Comparable & findMin( )   const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return root->element;
    }
    // ����ڵ� x
    void insert( const Comparable & x )
    {
        root = merge( new LeftistNode{ x }, root );
    }
    // ɾ����С��
    void deleteMin( )
    {
        if( isEmpty( ) )
           throw UnderflowException{ };
        
        LeftistNode* oldRoot = root;
        root = merge( root->left, root->right );
        delete oldRoot;
    }
    // ɾ����Сֵ
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
    // �� rhs �ϲ������ȶ���
    void merge( LeftistHeap & rhs )
    {
        if( this == &rhs )                      // rhs ���벻ͬ�� this
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
        int npl;                // ��·����
        LeftistNode( const Comparable & e, LeftistNode* lt = nullptr, 
                    LeftistNode* rt = nullptr, int np = 0 )
        : element{ e }, left{ lt }, right{ rt }, npl{ np }
        {

        }

    };

    LeftistNode* root;          // ���ڵ�
    // �ϲ�������
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
    // �ϲ�������ʽ�� h1 < h2
    LeftistNode* merge1( LeftistNode* h1, LeftistNode* h2 )
    {
        // ���ڵ�
        // ��ʽ����� h->left = nullptr, �� h->right = nullptr
        if( h1->left == nullptr )           
            h1->left = h2;
        else
        {
            // �ݹ�ϲ����ڵ�С������������ڵ�����
            h1->right = merge( h1->right, h2 );        
            // ����������·����С������������·����ʱ������������
            if( h1->left->npl < h1->right->npl )
                swapChildren( h1 );
            // ���ڵ����·���� = ��������·���� + 1 
            h1->npl = h1->right->npl + 1; 
        }

        return h1;
    }
    // ����һ���ڵ�����Ҷ���
    void swapChildren( LeftistNode* t )
    {
        LeftistNode* tempNode = t->left; 
        t->left = t->right;
        t->right = tempNode;
    }
    // ���ĳ����
    void reclaimMemory( LeftistNode* t )
    {
        if( t != nullptr )
        {
            reclaimMemory( t->left );
            reclaimMemory( t->right );
            delete t;
        }
    }
    // ��¡�ڵ�
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