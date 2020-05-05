/*
 * @Author: lsyy
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-04-05 11:55:17
 * @LastEditors: Please set LastEditors
 * @Description: SplayTree ��
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

	// ��¡����
	SplayTreeNode* clone( SplayTreeNode* t )	const
	{
		if ( t == t->left )
			return nullNode;
		else
			return new SplayTreeNode( t->element, clone( t->left ), clone( t->right ) );
	}
	void RightRotate( SplayTreeNode*& k2 )						// �� LL �Ͳ����������
	{
		SplayTreeNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2 = k1;
	}
	void LeftRotate( SplayTreeNode*& k2 )						// �� RR �Ͳ����������
	{
		SplayTreeNode* k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		k2 = k1;
	}
	void splay( const Object & x, SplayTreeNode* & t )			// �Զ�����չ������
	{
		SplayTreeNode *leftTreeMax, *rightTreeMin;
		static SplayTreeNode header;

		header.left = header.right = nullNode;
		leftTreeMax = rightTreeMin = &header;

		nullNode->element = x;									// ��֤�Ƚ�ʱƥ��

		for( ; ; )
			if( x < t->element )								// LL ��
			{
				if( x < t->left->element )						// zig-zig ��һ��
					RightRotate( t );
				if( t->left == nullNode )						// �ҵ���Ԫ�� ����ѭ��
					break;
				
				// �������
				rightTreeMin -> left = t;						// zig-zig �ڶ��� zig-zag ��һ�� ����ת ��һ��
				rightTreeMin = t;
				t = t->left;									// ����ѭ������
			}
			else if( t->element < x )							// RR ��
			{
				if( x < t->right->element )						// zig-zig ��һ��
					LeftRotate( t );
				if( t->right == nullNode )						// �ҵ���Ԫ�� ����ѭ��
					break;
				
				// �������
				leftTreeMax -> right = t;						// zig-zig �ڶ��� zig-zag ��һ�� ����ת ��һ��
				leftTreeMax = t;
				t = t->right;									// ����ѭ������
			}
			else
				break;
			

			// �ϲ���������
			leftTreeMax -> right = t -> left;
			rightTreeMin -> left = t ->right;
			t -> left = header.right;
			t -> right = header.left;
				
	}
	
	// �����ӡһ������
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
	// ���� =
	SplayTree& operator = ( const SplayTree& rhs )
	{
		if( this != &rhs )
		{
			makeEmpty( );
			this->root = clone( rhs.root );
		}
		
		return *this;
	}
	// �ж����Ƿ�Ϊ��
	bool isEmpty( )	const
	{
		return root == nullNode;
	}
	// �ж��������Ƿ���x
	bool contains( const Object & x )
    {
        if( isEmpty( ) )
            return false;
        splay( x, root );
        return root->element == x;
    }

	// �����в����½ڵ�
	void insert( const Object& x )
	{
		static SplayTreeNode* newNode = nullptr;

		if( newNode == nullptr )
			newNode = new SplayTreeNode;
		
		newNode -> element = x;

		if( root == nullNode )									// ����
		{
			newNode -> left = newNode -> right = nullNode;
			root = newNode;
		}
		else
		{
			splay( x, root );									// �Զ�������չ ����ʹ�� x �����Ԫ��Ϊ���ڵ�
			if ( x < root->element )
			{
				newNode -> left = root -> left;
				newNode -> right = root;
				root -> left = nullNode;						// �����Ͼ��� nullptr ָ��
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
				return;											// �ظ�Ԫ����
		}

		newNode = nullptr;										// ����һ�β��뽫���� new
		
	}
	// ɾ��Ԫ��
	void remove( const Object & x )
	{
		if( !contains( x ) )
			return;												// û���ҵ� x Ԫ��
		
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
	// �����ӡ��
	void printTree( )
	{
		if( isEmpty() )
			std::cout << " Empty Tree " << std::endl;
		else
			printTree( root );
	}
	// ����������СԪ��
	const Object& findMin( )
	{
		if( isEmpty() )
			std::cout << "Empty Tree" << std::endl;
		
		SplayTreeNode* ptr = root;

		// �����һ��������Ԫ��
		while ( ptr->left != nullNode )
			ptr = ptr->left;
		
		// ��չԪ�ص���Сֵ��������
		splay( ptr->element, root );
			return ptr->element;
		
	}
	// �����������Ԫ��
	const Object& findMax( )
	{
		if( isEmpty() )
			std::cout << "Empty Tree" << std::endl;
		
		SplayTreeNode* ptr = root;

		// �����һ��������Ԫ��
		while ( ptr->right != nullNode )
			ptr = ptr->right;
		
		// ��չԪ�ص���Сֵ��������
		splay( ptr->element, root );
			return ptr->element;
		
	}
	// �����
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