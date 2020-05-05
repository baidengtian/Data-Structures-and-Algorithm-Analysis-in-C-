/*
 * @Author: lsyy
 * @Date: 2020-04-01 21:02:49
 * @LastEditTime: 2020-04-01 21:56:32
 * @LastEditors: lsyy
 * @Description: list 容器实现
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

		Object  data;				// 当前节点保存的数据
		Node   *prev;				// 指向前一个节点
		Node   *next;				// 指向后一个节点

		Node( const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr )
			: data{ d }, prev{ p }, next{ n } { }

		Node( Object && d, Node * p = nullptr, Node * n = nullptr )
			: data{ std::move( d ) }, prev{ p }, next{ n } { }
	};

	int	 theSize;					// 链表大小
	Node *head;						// 指向头结点
	Node *tail;						// 指向尾节点
	// 初始化链表
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

		// 构造函数
		const_iterator( ) : current{ nullptr }
		{ }

		// 重载*
		const Object & operator* ( ) const
		{ return retrieve( ); }
		// 重载先加运算
		const_iterator & operator++ ( ){
			current = current->next;
			return *this;
		}
		// 重载后加
		const_iterator operator++ ( int ){
			const_iterator old = *this;
			++( *this );
			return old;
		}
		// 先－
		const_iterator & operator-- ( ){
			current = current->prev;
			return *this;
		}
		// 后减
		const_iterator operator-- ( int ){
			const_iterator old = *this;
			--( *this );
			return old;
		}
		// 重载 ==
		bool operator== ( const const_iterator & rhs ) const
		{ return current == rhs.current; }
		// 重载 !=
		bool operator!= ( const const_iterator & rhs ) const
		{ return !( *this == rhs ); }

	protected:
		Node *current;
		// 返回 current 指向的数据的引用  可以改变
		Object & retrieve( ) const
		{ return current->data; }

		// 构造函数
		const_iterator( Node *p ) :  current{ p }
		{ }
		// 基于 List 类访问 const_iterator 类 protected 成员的权利
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
	// 无参构造函数
	List( )
	{ init( ); }

	~List( )
	{
		clear( );
		delete head;
		delete tail;
	}
	// 拷贝构造
	List( const List & rhs )
	{
		init( );
		for( auto & x : rhs )
			push_back( x );
	}
	// 重载拷贝
	List & operator= ( const List & rhs )
	{
		List copy = rhs;
		std::swap( *this, copy );
		return *this;
	}

	// 移动构造函数
	List( List && rhs )
		: theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
	{
		rhs.theSize = 0;
		rhs.head = nullptr;
		rhs.tail = nullptr;
	}
	// 移动拷贝函数
	List & operator= ( List && rhs )
	{    
		std::swap( theSize, rhs.theSize );
		std::swap( head, rhs.head );
		std::swap( tail, rhs.tail );

		return *this;
	}

	// 返回起始迭代器
	iterator begin( )
	{ return iterator( head->next ); }

	const_iterator begin( ) const
	{ return const_iterator( head->next ); }

	iterator end( )
	{ return iterator( tail ); }

	const_iterator end( ) const
	{ return const_iterator( tail ); }

	// 返回 List 大小
	int size( ) const
	{ return theSize; }

	// 判断 List 是否为空
	bool empty( ) const
	{ return size( ) == 0; }

	// 清空 List
	void clear( )
	{
		while( !empty( ) )
			pop_front( );
	}

	// 返回第一个头结点
	Object & front( )
	{ return *begin( ); }

	const Object & front( ) const
	{ return *begin( ); }

	Object & back( )
	{ return *--end( ); }

	const Object & back( ) const
	{ return *--end( ); }

	// 表头插入
	void push_front( const Object & x )
	{ insert( begin( ), x ); }

	// 表未插入
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


