/*
 * @Author: lsyy
 * @Date: 2020-03-23 17:44:24
 * @LastEditTime: 2020-03-23 21:20:33
 * @LastEditors: Please set LastEditors
 * @Description: treap 树类
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
    // 深拷贝
    Treap & operator = ( const Treap & rhs ){
        // std::cout << "=前" << std::endl;
        Treap copy = rhs;
        // std::cout << "=后" << std::endl;
        std::swap( copy, *this );
        return *this;
    }
    // 移动
    Treap & operator=( Treap && rhs )
    {
        // std::cout << "MOVE" << std::endl;
        std::swap( root, rhs.root );
        std::swap( nullNode, rhs.nullNode );
        
        return *this;
    }
    // 插入
    void insert( const Comparable & x ){
        insert( x, root );
    }
    // 删除
    void remove( const Comparable & x ){
        remove( x, root );
    } 
    // 中序打印
    void print( ){
        print( root );
    }
    // 判断树是否为空
    bool isEmpty( ) const {
        if( root == nullNode )
            return true;
        return false;
    }
    // 判断树中是否包含 x 元素
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
    // 清空树
    void makeEmpty( ) {
        makeEmpty( root );
    }
    // 寻找最小值  
    Comparable findMin( ){
        return findMin( root );
    }
    // 寻找最大值
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

    // 在子树中插入节点
    void insert( const Comparable & x, TreapNode *& t ){

        if( t == nullNode ){
            t = new TreapNode{ x, nullNode, nullNode, randomNums.nextInt( ) };
        }           
        else if( x < t->element ){
            insert( x, t->left );
            // 任意节点的优先级大于等于其父节点的优先级
            if( t->left->priority < t->priority )
                rotateWithLeftChild( t );
        }
        else if( t->element < x ){
            insert( x, t->right );
            if( t->right->priority < t->priority )
                rotateWithRightChild( t );
        }
    }
    
    // 移除子树的某个节点
    void remove( const Comparable & x, TreapNode *& t ){
        if( t != nullNode ){
            if( x < t->element )
                remove( x, t->left );
            else if( x > t->element )
                remove( x, t->right );
            else{
                // 找到匹配
                if( t->left->priority < t->right->priority )
                    rotateWithLeftChild( t );
                else 
                    rotateWithRightChild( t );

                if( t != nullNode )                 // 继续下行
                    remove( x, t );
                else{
                    delete t->left;
                    t->Left = nullNode;             // 在叶节点上
                }
            }
        }
    }

    // 右旋转
    void rotateWithLeftChild( TreapNode * & k2 ){
        TreapNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }
    // 左旋转
    void rotateWithRightChild( TreapNode * & k1 ){
        TreapNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }
    // 打印子树
    void print( TreapNode *t )
    {
        if( t != nullNode ){
            print( t->left );
            std::cout << t->element << " : " << t->priority << std::endl;
            print( t->right );
        }
    }
    // 克隆
    TreapNode *clone( TreapNode *t ){
        // 这里不可以使用 t == nullNode 
        // 因为此时 nullNode = this->nullNode 而不是 t->nullNode
        if( t == t->left )
            return nullNode;
        else
            return new TreapNode{ t->element, clone( t->left ), clone( t->right ), t->priority };
    }
    // 清空子树
    void makeEmpty( TreapNode *& t ){
        if( t != nullNode ){
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullNode;
    }
    // 寻找子树最小值    
    Comparable findMin( const TreapNode *t ) { 
        if( isEmpty( ) )
            throw UnderflowException{ };
        if( t->left != nullNode )
            findMin( t->left );
        else
            return t->element;
    }
    // 寻找子树最大值
    Comparable findMax( const TreapNode *t ) { 
        if( isEmpty( ) )
            throw UnderflowException{ };
        if( t->right != nullNode )
            findMax( t->right );
        else
            return t->element;
    }
};


