/*
 * @Author: lsyy
 * @Date: 2020-03-23 17:44:24
 * @LastEditTime: 2020-03-23 21:20:33
 * @LastEditors: Please set LastEditors
 * @Description: treap ����
 * @FilePath: \treap tree\Inc\treap.h
 */
#pragma

#include <iostream>
#include <climits>
#include "Uniformrandom.h"
#include "dsexceptions.h"


template < typename Comparable >
class Treap
{
public:  
    Treap( ){
        nullNode = new TreapNode;
        nullNode->left = nullNode->right = nullNode;
        nullNode->priority = INT_MAX;
        root = nullNode;
    }
    Treap( const Treap & rhs ){
        nullNode = new TreapNode;
        nullNode->left = nullNode->right = nullNode;
        nullNode->priority = INT_MAX;
        root = clone( rhs.root );
        // std::cout << "copy" << std::endl;
    }
    ~Treap( ){
        makeEmpty( );
        delete nullNode;
    }
    // ���
    Treap & operator = ( const Treap & rhs ){
        // std::cout << "=ǰ" << std::endl;
        Treap copy = rhs;
        // std::cout << "=��" << std::endl;
        std::swap( copy, *this );
        return *this;
    }
    // �ƶ�
    Treap & operator=( Treap && rhs )
    {
        // std::cout << "MOVE" << std::endl;
        std::swap( root, rhs.root );
        std::swap( nullNode, rhs.nullNode );
        
        return *this;
    }
    // ����
    void insert( const Comparable & x ){
        insert( x, root );
    }
    // ɾ��
    void remove( const Comparable & x ){
        remove( x, root );
    } 
    // �����ӡ
    void print( ){
        print( root );
    }
    // �ж����Ƿ�Ϊ��
    bool isEmpty( ) const {
        if( root == nullNode )
            return true;
        return false;
    }
    // �ж������Ƿ���� x Ԫ��
    bool contains( const Comparable & x )   const {
        TreapNode *current = root;
        nullNode->element = x;
        while ( 1 ){
            if( x < current->element ){
                current = current->left;
            }
            else if( x > current->element ){
                current = current->right;
            }
            else{
                return current != nullNode;
            }
        }
        
    }
    // �����
    void makeEmpty( ) {
        makeEmpty( root );
    }
    // Ѱ����Сֵ  
    Comparable findMin( ){
        return findMin( root );
    }
    // Ѱ�����ֵ
    Comparable findMax( ){
        return findMax( root );
    }

private:
    struct TreapNode {

        Comparable element;
        TreapNode *left;
        TreapNode *right;
        int priority; 
        TreapNode( ) : left( nullptr ), right( nullptr ), priority( INT_MAX ) { }
        TreapNode( const Comparable & e, TreapNode *lt, TreapNode *rt, int pr )
        : element{ e }, left{ lt }, right{ rt }, priority{ pr } { }
    }; 
    TreapNode *root;
    TreapNode *nullNode;
    UniformRandom randomNums;

    // �������в���ڵ�
    void insert( const Comparable & x, TreapNode *& t ){

        if( t == nullNode ){
            t = new TreapNode{ x, nullNode, nullNode, randomNums.nextInt( ) };
        }           
        else if( x < t->element ){
            insert( x, t->left );
            // ����ڵ�����ȼ����ڵ����丸�ڵ�����ȼ�
            if( t->left->priority < t->priority )
                rotateWithLeftChild( t );
        }
        else if( t->element < x ){
            insert( x, t->right );
            if( t->right->priority < t->priority )
                rotateWithRightChild( t );
        }
    }
    
    // �Ƴ�������ĳ���ڵ�
    void remove( const Comparable & x, TreapNode *& t ){
        if( t != nullNode ){
            if( x < t->element )
                remove( x, t->left );
            else if( x > t->element )
                remove( x, t->right );
            else{
                // �ҵ�ƥ��
                if( t->left->priority < t->right->priority )
                    rotateWithLeftChild( t );
                else 
                    rotateWithRightChild( t );

                if( t != nullNode )                 // ��������
                    remove( x, t );
                else{
                    delete t->left;
                    t->Left = nullNode;             // ��Ҷ�ڵ���
                }
            }
        }
    }

    // ����ת
    void rotateWithLeftChild( TreapNode * & k2 ){
        TreapNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }
    // ����ת
    void rotateWithRightChild( TreapNode * & k1 ){
        TreapNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }
    // ��ӡ����
    void print( TreapNode *t )
    {
        if( t != nullNode ){
            print( t->left );
            std::cout << t->element << " : " << t->priority << std::endl;
            print( t->right );
        }
    }
    // ��¡
    TreapNode *clone( TreapNode *t ){
        // ���ﲻ����ʹ�� t == nullNode 
        // ��Ϊ��ʱ nullNode = this->nullNode ������ t->nullNode
        if( t == t->left )
            return nullNode;
        else
            return new TreapNode{ t->element, clone( t->left ), clone( t->right ), t->priority };
    }
    // �������
    void makeEmpty( TreapNode *& t ){
        if( t != nullNode ){
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullNode;
    }
    // Ѱ��������Сֵ    
    Comparable findMin( const TreapNode *t ) { 
        if( isEmpty( ) )
            throw UnderflowException{ };
        if( t->left != nullNode )
            findMin( t->left );
        else
            return t->element;
    }
    // Ѱ���������ֵ
    Comparable findMax( const TreapNode *t ) { 
        if( isEmpty( ) )
            throw UnderflowException{ };
        if( t->right != nullNode )
            findMax( t->right );
        else
            return t->element;
    }
};


