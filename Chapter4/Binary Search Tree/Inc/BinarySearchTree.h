/*
 * @Author: lsyy
 * @Date: 2020-02-10 10:13:13
 * @LastEditTime: 2020-04-22 15:57:25
 * @LastEditors: Please set LastEditors
 * @Description: BinarySearchTree ��غ���
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
	// ���� =
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
	// �ж��������Ƿ���x
	bool contains( const Object& x )	const
	{
		return contains( x, root );
	}
	bool isEmpty( )	const
	{
		return root == nullptr;
	}
	void printTree( std::ostream& out = std::cout )	const;

	// �����
	void makeEmpty( )
	{
		makeEmpty(root);
	}
	// �����в����½ڵ�
	void insert( const Object& x )
	{
		insert( x, root );
	}
	// �������Ƴ��ڵ�
	void remove( const Object& x )
    {
        remove( x, root );
    }
	// �����ӡ��
	void MidPrintTree( std::ostream & out = std::cout )	
	{
		if( isEmpty() )
			out << "Empty tree" << std::endl;
		else
			MidPrintTree( root, out );
	}
	// ǰ���ӡ��
	void ProPrintTree( std::ostream & out = std::cout )	
	{
		if( isEmpty() )
			out << "Empty tree" << std::endl;
		else
			ProPrintTree( root, out );
	}
	// �����ӡ��
	void LastPrintTree( std::ostream & out = std::cout )	
	{
		if( isEmpty() )
			out << "Empty tree" << std::endl;
		else
			LastPrintTree( root, out );
	}
	// �õ������Ľڵ���
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
	// �����½ڵ�
	void insert( const Object& x, BinaryNode*& t )
	{
		if ( t == nullptr ) 
			t = new BinaryNode(x,nullptr,nullptr);              // �����½ڵ� 
		else if( x < t->element )
			insert( x, t->left );
		else if( x > t->element )
			insert( x, t->right );
		else
			;			// �ظ�Ԫ;ʲô������
		// t ����ָ�� root
			 
	}
	// x ��Ҫ��ɾ���� t Ϊ�������Ľڵ�
	void remove( const Object& x, BinaryNode*& t )				// ɾ��һ���ڵ�
	{
		if ( t == nullptr )
			return;												// ʲô��û��;ʲôҲ����
		if ( x < t->element )
			remove( x, t->left );
		else if ( t->element < x )
			remove( x, t->right );
		else if ( t->left != nullptr && t->right != nullptr )	// ����������
		{
			t->element = findMin( t->right )->element;			// Ѱ���������е���Сֵ ������������Сֵ�����ֵ 
			remove( t->element, t->right );						// ɾ����������Сֵ
		}
		else                                                    // ɾ��һ�����ӵ�
		{
			BinaryNode *oldNode = t;
			t = ( t->left != nullptr ) ? t->left : t->right;
			delete oldNode;
		}
			 
	}
	// Ѱ����Сֵ
	BinaryNode* findMin( BinaryNode* t )	const
	{
		if ( t == nullptr )
			return nullptr;
		if ( t->left == nullptr)
			return t;
		return findMin( t->left );
	}
	// Ѱ�����ֵ
	BinaryNode* findMax( BinaryNode* t )	const
	{
		if ( t != nullptr )
			while( t->right != nullptr )
				t = t->right;
		return t;
	}
	// ��������Ѱ��ĳ���ڵ�
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
	// �������
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

	// ��¡����
	BinaryNode* clone( BinaryNode* t )	const
	{
		if ( t == nullptr )
			return nullptr;
		else
			return new BinaryNode( t->element, clone( t->left ), clone( t->right ) );
	}
	// �����ӡ����
	void MidPrintTree( BinaryNode* t, std::ostream & out )
	{
		if( t != nullptr )
		{
			MidPrintTree( t->left, out );
			out << t->element << std::endl;
			MidPrintTree( t->right, out );
		}
	}
	// ǰ���ӡ����
	void ProPrintTree( BinaryNode* t, std::ostream & out )
	{
		if( t != nullptr )
		{
			out << t->element << std::endl;
			ProPrintTree( t->left, out );
			ProPrintTree( t->right, out );
		}
	}
	// �����ӡ����
	void LastPrintTree( BinaryNode* t, std::ostream & out )
	{
		if( t != nullptr )
		{	
			LastPrintTree( t->left, out );
			LastPrintTree( t->right, out );
			out << t->element << std::endl;
		}
	}
	
	// �õ������Ľڵ���
	int CountNodesTail( BinaryNode *t ){
		if( t == nullptr )
			return 0;
		else
			return CountNodesTail( t->left ) + CountNodesTail( t->right ) + 1;
	}
	// �õ������Ľڵ���
	// ��δ����һ�������ı������Ż���Ϊβ���ݹ飬����һ��ѭ���滻һ���ݹ���ã�
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
