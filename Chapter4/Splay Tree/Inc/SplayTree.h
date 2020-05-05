/*
 * @Author: lsyy
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-04-05 11:55:17
 * @LastEditors: Please set LastEditors
 * @Description: SplayTree 类
 * @FilePath: \Splay Tree\Inc\SplayTree.h
 */

#ifndef __SPLAYTREE_H                                                                                                                                                                                                                                                                                                                                                     
#define __SPLAYTREE_H

#include <iostream>
#include <algorithm>


template < typename Object >

class SplayTree
{

private:
	struct SplayTreeNode
	{
		Object element;
		SplayTreeNode* left;
		SplayTreeNode* right;
		SplayTreeNode( ) : left( NULL ), right( NULL ) { }
		SplayTreeNode( const Object& theElement, SplayTreeNode *lt, SplayTreeNode *rt ) 
			: element( theElement ), left( lt ), right( rt ){ }
	};
	SplayTreeNode* root;
	SplayTreeNode* nullNode;

	// 克隆子树
	SplayTreeNode* clone( SplayTreeNode* t )	const
	{
		if ( t == t->left )
			return nullNode;
		else
			return new SplayTreeNode( t->element, clone( t->left ), clone( t->right ) );
	}
	void RightRotate( SplayTreeNode*& k2 )						// 对 LL 型插入进行右旋
	{
		SplayTreeNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2 = k1;
	}
	void LeftRotate( SplayTreeNode*& k2 )						// 对 RR 型插入进行左旋
	{
		SplayTreeNode* k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		k2 = k1;
	}
	void splay( const Object & x, SplayTreeNode* & t )			// 自顶向下展开方法
	{
		SplayTreeNode *leftTreeMax, *rightTreeMin;
		static SplayTreeNode header;

		header.left = header.right = nullNode;
		leftTreeMax = rightTreeMin = &header;

		nullNode->element = x;									// 保证比较时匹配

		for( ; ; )
			if( x < t->element )								// LL 型
			{
				if( x < t->left->element )						// zig-zig 第一步
					RightRotate( t );
				if( t->left == nullNode )						// 找到该元素 跳出循环
					break;
				
				// 链接左侧
				rightTreeMin -> left = t;						// zig-zig 第二步 zig-zag 第一步 单旋转 第一步
				rightTreeMin = t;
				t = t->left;									// 用于循环迭代
			}
			else if( t->element < x )							// RR 型
			{
				if( x < t->right->element )						// zig-zig 第一步
					LeftRotate( t );
				if( t->right == nullNode )						// 找到该元素 跳出循环
					break;
				
				// 链接左侧
				leftTreeMax -> right = t;						// zig-zig 第二步 zig-zag 第一步 单旋转 第一步
				leftTreeMax = t;
				t = t->right;									// 用于循环迭代
			}
			else
				break;
			

			// 合并左中右树
			leftTreeMax -> right = t -> left;
			rightTreeMin -> left = t ->right;
			t -> left = header.right;
			t -> right = header.left;
				
	}
	
	// 中序打印一个子树
	void printTree(const SplayTreeNode* t )	const
	{
		if( t != nullNode )
		{
			printTree( t->left );
			std::cout << t->element << std::endl;
			printTree( t->right );
		}
	}
public:

	SplayTree( ) 
	{
		nullNode = new SplayTreeNode;
		nullNode -> left = nullNode -> right = nullNode;
		root = nullNode;
	}
	SplayTree( const SplayTree& rhs )
	{
		// root = clone( rhs.root );
		nullNode = new SplayTreeNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
        *this = rhs;
	}
	~SplayTree()
	{
		makeEmpty( );
		delete nullNode;
	}
	// 重载 =
	SplayTree& operator = ( const SplayTree& rhs )
	{
		if( this != &rhs )
		{
			makeEmpty( );
			this->root = clone( rhs.root );
		}
		
		return *this;
	}
	// 判断树是否为空
	bool isEmpty( )	const
	{
		return root == nullNode;
	}
	// 判断在树上是否含有x
	bool contains( const Object & x )
    {
        if( isEmpty( ) )
            return false;
        splay( x, root );
        return root->element == x;
    }

	// 在树中插入新节点
	void insert( const Object& x )
	{
		static SplayTreeNode* newNode = nullptr;

		if( newNode == nullptr )
			newNode = new SplayTreeNode;
		
		newNode -> element = x;

		if( root == nullNode )									// 空树
		{
			newNode -> left = newNode -> right = nullNode;
			root = newNode;
		}
		else
		{
			splay( x, root );									// 自顶向下扩展 最终使离 x 最近的元素为根节点
			if ( x < root->element )
			{
				newNode -> left = root -> left;
				newNode -> right = root;
				root -> left = nullNode;						// 理论上就是 nullptr 指针
				root = newNode;
			}
			else if( root->element < x )
			{
				newNode -> right = root -> right;
				newNode -> left = root;
				root -> right = nullNode;
				root = newNode;
			}
			else
				return;											// 重复元操作
		}

		newNode = nullptr;										// 故下一次插入将调用 new
		
	}
	// 删除元素
	void remove( const Object & x )
	{
		if( !contains( x ) )
			return;												// 没有找到 x 元素
		
		SplayTreeNode* newTree;

		if( root -> left == nullNode )
			newTree = root -> right;
		else
		{
			newTree = root -> left;
			splay( x, newTree );
			newTree -> right = root -> right;
		}
		delete root;
		root = newTree;
		
	}
	// 中序打印树
	void printTree( )
	{
		if( isEmpty() )
			std::cout << " Empty Tree " << std::endl;
		else
			printTree( root );
	}
	// 查找树中最小元素
	const Object& findMin( )
	{
		if( isEmpty() )
			std::cout << "Empty Tree" << std::endl;
		
		SplayTreeNode* ptr = root;

		// 找左边一条边最后的元素
		while ( ptr->left != nullNode )
			ptr = ptr->left;
		
		// 伸展元素到最小值到树根处
		splay( ptr->element, root );
			return ptr->element;
		
	}
	// 查找树中最大元素
	const Object& findMax( )
	{
		if( isEmpty() )
			std::cout << "Empty Tree" << std::endl;
		
		SplayTreeNode* ptr = root;

		// 找左边一条边最后的元素
		while ( ptr->right != nullNode )
			ptr = ptr->right;
		
		// 伸展元素到最小值到树根处
		splay( ptr->element, root );
			return ptr->element;
		
	}
	// 清空树
	void makeEmpty( )
	{
		while( !isEmpty( ) )
        {
		// Splay max item to root
            findMax( );        				
            remove( root->element );
        }
	}
};

 


#endif 