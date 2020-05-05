/*
 * @Author: lsyy
 * @Date: 2020-04-01 21:02:49
 * @LastEditTime: 2020-04-01 21:56:32
 * @LastEditors: lsyy
 * @Description: list ����ʵ��
 * @FilePath: \List\Inc\List.h
 */

#pragma


#include <algorithm>
using namespace std;

template <typename Object>
class List
{
private:    
	
	struct Node{

		Object  data;				// ��ǰ�ڵ㱣�������
		Node   *prev;				// ָ��ǰһ���ڵ�
		Node   *next;				// ָ���һ���ڵ�

		Node( const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr )
			: data{ d }, prev{ p }, next{ n } { }

		Node( Object && d, Node * p = nullptr, Node * n = nullptr )
			: data{ std::move( d ) }, prev{ p }, next{ n } { }
	};

	int	 theSize;					// �����С
	Node *head;						// ָ��ͷ���
	Node *tail;						// ָ��β�ڵ�
	// ��ʼ������
	void init( ){
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
public:
	class const_iterator{
	public:

		// ���캯��
		const_iterator( ) : current{ nullptr }
		{ }

		// ����*
		const Object & operator* ( ) const
		{ return retrieve( ); }
		// �����ȼ�����
		const_iterator & operator++ ( ){
			current = current->next;
			return *this;
		}
		// ���غ��
		const_iterator operator++ ( int ){
			const_iterator old = *this;
			++( *this );
			return old;
		}
		// �ȣ�
		const_iterator & operator-- ( ){
			current = current->prev;
			return *this;
		}
		// ���
		const_iterator operator-- ( int ){
			const_iterator old = *this;
			--( *this );
			return old;
		}
		// ���� ==
		bool operator== ( const const_iterator & rhs ) const
		{ return current == rhs.current; }
		// ���� !=
		bool operator!= ( const const_iterator & rhs ) const
		{ return !( *this == rhs ); }

	protected:
		Node *current;
		// ���� current ָ������ݵ�����  ���Ըı�
		Object & retrieve( ) const
		{ return current->data; }

		// ���캯��
		const_iterator( Node *p ) :  current{ p }
		{ }
		// ���� List ����� const_iterator �� protected ��Ա��Ȩ��
		friend class List<Object>;
	};

	class iterator : public const_iterator{		
	public:

		iterator( )
		{ }

		Object & operator* ( )
		{ return const_iterator::retrieve( ); }

		const Object & operator* ( ) const
		{ return const_iterator::operator*( ); }

		iterator & operator++ ( ){
			this->current = this->current->next;
			return *this;
		}

		iterator operator++ ( int ){
			iterator old = *this;
			++( *this );
			return old;
		}

		iterator & operator-- ( ){
			this->current = this->current->prev;
			return *this;
		}

		iterator operator-- ( int ){
			iterator old = *this;
			--( *this );
			return old;
		}

	protected:

		iterator( Node *p ) : const_iterator{ p }
		{ }

		friend class List<Object>;
	};

public:
	// �޲ι��캯��
	List( )
	{ init( ); }

	~List( )
	{
		clear( );
		delete head;
		delete tail;
	}
	// ��������
	List( const List & rhs )
	{
		init( );
		for( auto & x : rhs )
			push_back( x );
	}
	// ���ؿ���
	List & operator= ( const List & rhs )
	{
		List copy = rhs;
		std::swap( *this, copy );
		return *this;
	}

	// �ƶ����캯��
	List( List && rhs )
		: theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
	{
		rhs.theSize = 0;
		rhs.head = nullptr;
		rhs.tail = nullptr;
	}
	// �ƶ���������
	List & operator= ( List && rhs )
	{    
		std::swap( theSize, rhs.theSize );
		std::swap( head, rhs.head );
		std::swap( tail, rhs.tail );

		return *this;
	}

	// ������ʼ������
	iterator begin( )
	{ return iterator( head->next ); }

	const_iterator begin( ) const
	{ return const_iterator( head->next ); }

	iterator end( )
	{ return iterator( tail ); }

	const_iterator end( ) const
	{ return const_iterator( tail ); }

	// ���� List ��С
	int size( ) const
	{ return theSize; }

	// �ж� List �Ƿ�Ϊ��
	bool empty( ) const
	{ return size( ) == 0; }

	// ��� List
	void clear( )
	{
		while( !empty( ) )
			pop_front( );
	}

	// ���ص�һ��ͷ���
	Object & front( )
	{ return *begin( ); }

	const Object & front( ) const
	{ return *begin( ); }

	Object & back( )
	{ return *--end( ); }

	const Object & back( ) const
	{ return *--end( ); }

	// ��ͷ����
	void push_front( const Object & x )
	{ insert( begin( ), x ); }

	// ��δ����
	void push_back( const Object & x )
	{ insert( end( ), x ); }

	void push_front( Object && x )
	{ insert( begin( ), std::move( x ) ); }

	void push_back( Object && x )
	{ insert( end( ), std::move( x ) ); }

	void pop_front( )
	{ erase( begin( ) ); }

	void pop_back( )
	{ erase( --end( ) ); }

	// Insert x before itr.
	iterator insert( iterator itr, const Object & x )
	{
		Node *p = itr.current;
		++theSize;
		return iterator( p->prev = p->prev->next = new Node{ x, p->prev, p } );
	}

	// Insert x before itr.
	iterator insert( iterator itr, Object && x )
	{
		Node *p = itr.current;
		++theSize;
		return iterator( p->prev = p->prev->next = new Node{ std::move( x ), p->prev, p } );
	}

	// Erase item at itr.
	iterator erase( iterator itr )
	{
		Node *p = itr.current;
		iterator retVal( p->next );
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		--theSize;

		return retVal;
	}

	iterator erase( iterator from, iterator to )
	{
		for( iterator itr = from; itr != to; )
			itr = erase( itr );

		return to;
	}


};


