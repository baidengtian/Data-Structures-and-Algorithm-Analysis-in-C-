/*
 * @Author: your name
 * @Date: 2020-02-10 21:29:36
 * @LastEditTime: 2020-04-04 22:03:29
 * @LastEditors: Please set LastEditors
 * @Description: AVLTree ��
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
	
	AvlNode* root;										// ���ڵ�

	int height( AvlNode* t )	const					// ���ؽڵ�t�ĸ߶�,�����nullptr�򷵻�-1
	{
		return t == nullptr ? -1 : t->height;
	}
	void insert( const Comparable & x, AvlNode*& t )	// ����ڵ�
	{
		if ( t == nullptr )
			t = new AvlNode( x, nullptr, nullptr );
		else if( x < t->element )
			insert( x, t->left );
		else if( x > t->element )
			insert( x, t->right );

		balance( t );									// ƽ�����ڵ㵽���ڵ��·���ϵ�ÿһ���ڵ�
	}
	static const int ALLOWED_IMBALANCE = 1;
	void balance( AvlNode*& t )							// ƽ��ڵ�
	{
		if ( t == nullptr )
			return;
		// int deep = height( t->left );
		// deep = height( t->right );
		if ( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
			if( height( t->left->left ) >= height( t->left->right ) )			// LL�Ͳ��� ����һ������
				RightRotate( t );
			else																// LR�Ͳ��� �Ƚ���һ������ �ٽ���һ������
				LRdoubleRotate( t );
		else if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
			if( height( t->right->right ) >= height( t->right->left ) )			// RR�Ͳ��� ����һ������
				LeftRotate( t );
			else																// LR�Ͳ��� �Ƚ���һ������ �ٽ���һ������
				RLdoubleRotate( t );
		t->height = std::max( height( t->left ), height( t->right )) + 1;		// ����ÿ���ڵ�߶�

	}
	void RightRotate( AvlNode*& k2 )				// �� LL �Ͳ����������
	{
		AvlNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2->height = std::max( height(k2->left), height(k2->right) ) + 1;
		k1->height = std::max( height(k1->left), k2->height ) + 1;
		k2 = k1;
	}
	void LeftRotate( AvlNode*& k2 )					// �� RR �Ͳ����������
	{
		AvlNode* k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		k2->height = std::max( height(k2->left), height(k2->right) ) + 1;
		k1->height = std::max( height(k1->right), k2->height ) + 1;
		k2 = k1;
	}
	void LRdoubleRotate( AvlNode*& k3 )				// �� LR �ͽ���˫��ת
	{
		LeftRotate( k3->left );
		RightRotate( k3 );
	}
	void RLdoubleRotate( AvlNode*& k3 )				// �� RL �ͽ���˫��ת
	{
		RightRotate( k3->right );
		LeftRotate( k3 );
	}
	void remove( const Comparable& x, AvlNode*& t)	// ���������Ƴ��ڵ�
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
	void makeEmpty( AvlNode* & t )					// �������
	{
		if( t != nullptr )
		{
			makeEmpty( t->left );
			makeEmpty( t->right );
			delete t;
		}
		t = nullptr;
	}
	AvlNode* clone( AvlNode* t )	const			// ��¡һ������
	{
		if( t == nullptr )
			return nullptr;
		else
			return new AvlNode( t->element, clone( t->left ), clone( t->right ), t->height );
	}
	bool contains( const Comparable & x, AvlNode* & t )	const	// �����������Ƿ���� x Ԫ��
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
	AvlNode* findMin( AvlNode* t )	const			// ������������Сֵ
	{
		if( t == nullptr )
			return nullptr;
		if( t->left == nullptr )
			return t;
		return findMin( t->left );

	}	
	AvlNode* findMax( AvlNode* t )	const			// �������������ֵ
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
	void remove( const Comparable & x )				// �������Ƴ�һ������
	{
		remove( x, root );
	}
	void insert( const Comparable & x )				// �������ݵ�����
	{
		insert( x, root );
	}
	void makeEmpty()								// ���������
	{
		makeEmpty( root );
	}
	bool isEmpty()	const							// �ж����Ƿ�Ϊ��
	{
		return root == nullptr;
	}
	bool contains( const Comparable & x )			// ���������Ƿ���� x Ԫ��
	{
		return contains( x, root );
	}
	const Comparable & findMin( )	const			// ����������СԪ��
	{
		return findMin( root ) -> element;
	}	
	const Comparable & findMax( )	const			// �����������Ԫ��
	{
		return findMax( root ) -> element;
	} 
	void BFSOrder( )	const{						// ��������
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
