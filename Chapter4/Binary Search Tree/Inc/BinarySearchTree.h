/*
 * @Author: lsyy
 * @Date: 2020-02-10 10:13:13
 * @LastEditTime: 2020-04-22 15:57:25
 * @LastEditors: Please set LastEditors
 * @Description: BinarySearchTree 相关函数
 * @FilePath: \WordMap\Inc\BinarySearchTree.h
 */
#ifndef __BINARYSEARCHTREE_H                                                                                                                                                                                                                                                                                                                                                     
#define __BINARYSEARCHTREE_H

#include <iostream>
#include <algorithm>


template < typename Object >

class BinarySearchTree
{
public:
	BinarySearchTree() : root( nullptr )
	{
	
	}
	BinarySearchTree( const BinarySearchTree& rhs ) : root( nullptr )
	{
		root = clone( rhs.root );
	}
	~BinarySearchTree()
	{
		makeEmpty( root );
	}
	// 重载 =
	BinarySearchTree& operator = ( const BinarySearchTree& rhs )
	{
		this->root = clone( rhs.root );
		return *this;
	}
	const Object& findMin( )	const
	{
		return findMin( root ) -> element;
	}
	const Object& findMax( )	const
	{
		return findMax( root ) -> element;
	}
	// 判断在树上是否含有x
	bool contains( const Object& x )	const
	{
		return contains( x, root );
	}
	bool isEmpty( )	const
	{
		return root == nullptr;
	}
	void printTree( std::ostream& out = std::cout )	const;

	// 清除树
	void makeEmpty( )
	{
		makeEmpty(root);
	}
	// 在树中插入新节点
	void insert( const Object& x )
	{
		insert( x, root );
	}
	// 从树中移除节点
	void remove( const Object& x )
    {
        remove( x, root );
    }
	// 中序打印树
	void MidPrintTree( std::ostream & out = std::cout )	
	{
		if( isEmpty() )
			out << "Empty tree" << std::endl;
		else
			MidPrintTree( root, out );
	}
	// 前序打印树
	void ProPrintTree( std::ostream & out = std::cout )	
	{
		if( isEmpty() )
			out << "Empty tree" << std::endl;
		else
			ProPrintTree( root, out );
	}
	// 后序打印树
	void LastPrintTree( std::ostream & out = std::cout )	
	{
		if( isEmpty() )
			out << "Empty tree" << std::endl;
		else
			LastPrintTree( root, out );
	}
	// 得到该树的节点数
	int CountNodesTail( )	{
		return CountNodesTail( root );
	}

private:
	struct BinaryNode
	{
		Object element;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode( const Object& theElement, BinaryNode *lt, BinaryNode *rt ) 
			: element( theElement ), left( lt ), right( rt ) { }
		BinaryNode( const Object&& theElement, BinaryNode *lt, BinaryNode *rt ) 
			: element( std::move(theElement) ), left( lt ), right( rt ) { }
	};
	BinaryNode* root;
	// 插入新节点
	void insert( const Object& x, BinaryNode*& t )
	{
		if ( t == nullptr ) 
			t = new BinaryNode(x,nullptr,nullptr);              // 插入新节点 
		else if( x < t->element )
			insert( x, t->left );
		else if( x > t->element )
			insert( x, t->right );
		else
			;			// 重复元;什么都不做
		// t 最终指向 root
			 
	}
	// x 是要被删除数 t 为该子树的节点
	void remove( const Object& x, BinaryNode*& t )				// 删除一个节点
	{
		if ( t == nullptr )
			return;												// 什么都没有;什么也不做
		if ( x < t->element )
			remove( x, t->left );
		else if ( t->element < x )
			remove( x, t->right );
		else if ( t->left != nullptr && t->right != nullptr )	// 有两个儿子
		{
			t->element = findMin( t->right )->element;			// 寻找右子树中的最小值 用右子树的最小值代替该值 
			remove( t->element, t->right );						// 删除右子树最小值
		}
		else                                                    // 删除一个儿子的
		{
			BinaryNode *oldNode = t;
			t = ( t->left != nullptr ) ? t->left : t->right;
			delete oldNode;
		}
			 
	}
	// 寻找最小值
	BinaryNode* findMin( BinaryNode* t )	const
	{
		if ( t == nullptr )
			return nullptr;
		if ( t->left == nullptr)
			return t;
		return findMin( t->left );
	}
	// 寻找最大值
	BinaryNode* findMax( BinaryNode* t )	const
	{
		if ( t != nullptr )
			while( t->right != nullptr )
				t = t->right;
		return t;
	}
	// 在子树中寻找某个节点
	bool contains( const Object& x, BinaryNode *t )	const
	{
		if( t == nullptr )
			return false;
		else if( x < t->element )
			return contains( x, t->left );
		else if( x > t->element )
			return contains( x, t->right );
		else
			return true; 

	}
	// 清空子树
	void makeEmpty( BinaryNode*& t )
	{
		if ( t != nullptr )
		{
			makeEmpty( t->left );
			makeEmpty( t->right );
			delete t;
		}
		t = nullptr;
	}

	// 克隆子树
	BinaryNode* clone( BinaryNode* t )	const
	{
		if ( t == nullptr )
			return nullptr;
		else
			return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
	}
	// 中序打印子树
	void MidPrintTree( BinaryNode* t, std::ostream & out )
	{
		if( t != nullptr )
		{
			MidPrintTree( t->left, out );
			out << t->element << std::endl;
			MidPrintTree( t->right, out );
		}
	}
	// 前序打印子树
	void ProPrintTree( BinaryNode* t, std::ostream & out )
	{
		if( t != nullptr )
		{
			out << t->element << std::endl;
			ProPrintTree( t->left, out );
			ProPrintTree( t->right, out );
		}
	}
	// 后序打印子树
	void LastPrintTree( BinaryNode* t, std::ostream & out )
	{
		if( t != nullptr )
		{	
			LastPrintTree( t->left, out );
			LastPrintTree( t->right, out );
			out << t->element << std::endl;
		}
	}
	
	// 得到子树的节点数
	int CountNodesTail( BinaryNode *t ){
		if( t == nullptr )
			return 0;
		else
			return CountNodesTail( t->left ) + CountNodesTail( t->right ) + 1;
	}
	// 得到子树的节点数
	// 这段代码的一个常见的编译器优化称为尾部递归，是用一个循环替换一个递归调用，
	// int CountNodesTail( BinaryNode *t ){
	// 	BinaryNode *x = t;
	// 	int s = 0;
	// 	while( x != nullptr ){
	// 		s = s + 1 + CountNodesTail( x->left );
	// 		x = x->right;
	// 	}
	// 	return s;
	// }

};

 


#endif
