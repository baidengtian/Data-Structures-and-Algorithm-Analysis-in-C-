/*
 * @Author: your name
 * @Date: 2020-02-10 21:29:36
 * @LastEditTime: 2020-04-04 22:03:29
 * @LastEditors: Please set LastEditors
 * @Description: AVLTree 类
 * @FilePath: \AVLTree\Inc\AVLTree.h
 */

#ifndef __AVLTREE_H                                                                                                                                                                                                                                                                                                                                                     
#define __AVLTREE_H

#include <iostream>
#include <algorithm>
#include <queue>


template < typename Comparable >

class AVLTree
{

private:
	struct AvlNode
	{
		Comparable element;
		AvlNode* left;
		AvlNode* right;
		int height;

		AvlNode( const Comparable& ele, AvlNode* lt, AvlNode* rt, int h = 0 )
			: element( ele ), left( lt ), right( rt ), height( h ){}

	};
	
	AvlNode* root;										// 根节点

	int height( AvlNode* t )	const					// 返回节点t的高度,如果是nullptr则返回-1
	{
		return t == nullptr ? -1 : t->height;
	}
	void insert( const Comparable & x, AvlNode*& t )	// 插入节点
	{
		if ( t == nullptr )
			t = new AvlNode( x, nullptr, nullptr );
		else if( x < t->element )
			insert( x, t->left );
		else if( x > t->element )
			insert( x, t->right );

		balance( t );									// 平衡插入节点到根节点的路径上的每一个节点
	}
	static const int ALLOWED_IMBALANCE = 1;
	void balance( AvlNode*& t )							// 平衡节点
	{
		if ( t == nullptr )
			return;
		// int deep = height( t->left );
		// deep = height( t->right );
		if ( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
			if( height( t->left->left ) >= height( t->left->right ) )			// LL型插入 进行一次右旋
				RightRotate( t );
			else																// LR型插入 先进行一次左旋 再进行一次右旋
				LRdoubleRotate( t );
		else if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
			if( height( t->right->right ) >= height( t->right->left ) )			// RR型插入 进行一次左旋
				LeftRotate( t );
			else																// LR型插入 先进行一次右旋 再进行一次左旋
				RLdoubleRotate( t );
		t->height = std::max( height( t->left ), height( t->right )) + 1;		// 更新每个节点高度

	}
	void RightRotate( AvlNode*& k2 )				// 对 LL 型插入进行右旋
	{
		AvlNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = std::max( height(k2->left), height(k2->right) ) + 1;
		k1->height = std::max( height(k1->left), k2->height ) + 1;
		k2 = k1;
	}
	void LeftRotate( AvlNode*& k2 )					// 对 RR 型插入进行左旋
	{
		AvlNode* k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		k2->height = std::max( height(k2->left), height(k2->right) ) + 1;
		k1->height = std::max( height(k1->right), k2->height ) + 1;
		k2 = k1;
	}
	void LRdoubleRotate( AvlNode*& k3 )				// 对 LR 型进行双旋转
	{
		LeftRotate( k3->left );
		RightRotate( k3 );
	}
	void RLdoubleRotate( AvlNode*& k3 )				// 对 RL 型进行双旋转
	{
		RightRotate( k3->right );
		LeftRotate( k3 );
	}
	void remove( const Comparable& x, AvlNode*& t)	// 从子树中移除节点
	{
		if( t == nullptr )
			return;
		if( x < t->element )
			remove( x, t->left );
		else if( x > t->element )
			remove( x, t->right );
		else if( t->left != nullptr && t->right != nullptr )
		{
			t->element = findMin( t->right )->element;
			remove( t->element, t->right );
		}
		else
		{
			AvlNode* oldNode = t;
		}
	}
	void makeEmpty( AvlNode* & t )					// 清空子树
	{
		if( t != nullptr )
		{
			makeEmpty( t->left );
			makeEmpty( t->right );
			delete t;
		}
		t = nullptr;
	}
	AvlNode* clone( AvlNode* t )	const			// 克隆一个子树
	{
		if( t == nullptr )
			return nullptr;
		else
			return new AvlNode( t->element, clone( t->left ), clone( t->right ), t->height );
	}
	bool contains( const Comparable & x, AvlNode* & t )	const	// 查找子树中是否包含 x 元素
	{
		if( t == nullptr )
			return false;
		if( x < t->element )
			contains( x, t->left );
		else if( x > t->element )
			contains( x, t->right );
		else
			return true;
	}
	AvlNode* findMin( AvlNode* t )	const			// 查找子树中最小值
	{
		if( t == nullptr )
			return nullptr;
		if( t->left == nullptr )
			return t;
		return findMin( t->left );

	}	
	AvlNode* findMax( AvlNode* t )	const			// 查找子树中最大值
	{
		if( t == nullptr )
			return nullptr;
		if( t->right == nullptr )
			return t;
		return findMax( t->right );
	} 
public:
	AVLTree() : root( nullptr )
	{

	}
	~AVLTree()
	{
		makeEmpty( root );
	}
	AVLTree( const AVLTree & rhs ) : root( nullptr )
	{
		this->root = clone( rhs.root );
	}
	AVLTree & operator = ( const AVLTree & rhs )
	{
		this->root = clone( rhs.root );
		return *this;
	}
	void remove( const Comparable & x )				// 从树中移除一个数据
	{
		remove( x, root );
	}
	void insert( const Comparable & x )				// 插入数据到树中
	{
		insert( x, root );
	}
	void makeEmpty()								// 清空整个树
	{
		makeEmpty( root );
	}
	bool isEmpty()	const							// 判断树是否为空
	{
		return root == nullptr;
	}
	bool contains( const Comparable & x )			// 查找树中是否包含 x 元素
	{
		return contains( x, root );
	}
	const Comparable & findMin( )	const			// 查找树中最小元素
	{
		return findMin( root ) -> element;
	}	
	const Comparable & findMax( )	const			// 查找树中最大元素
	{
		return findMax( root ) -> element;
	} 
	void BFSOrder( )	const{						// 层析遍历
		std::queue< AvlNode* > q;
		AvlNode *tmp;
		q.push( root );
		while( !q.empty( ) ){
			tmp = q.back( );
			q.pop( );
			std::cout << tmp->element << "	";
			if( tmp->left != nullptr )
				q.push( tmp->left );
			if( tmp->right != nullptr )
				q.push( tmp->right );
		}
	}
};





#endif
