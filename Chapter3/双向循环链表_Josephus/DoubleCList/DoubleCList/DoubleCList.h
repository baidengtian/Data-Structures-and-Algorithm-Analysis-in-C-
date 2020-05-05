#ifndef __DOUBLECLIST_H
#define __DOUBLECLIST_H

#include <iostream>
#include <algorithm>




template < typename Object >
class doubleCList
{
private:
	// 节点
	struct Node
	{
		Object  data;
		Node   *prev;
		Node   *next;

		Node( const Object & d = Object( ), Node * p = nullptr, Node * n = nullptr )
			: data( d ), prev( p ), next( n ) { }
	};
public:
	class const_iterator
	{
	public:

		// Public constructor for const_iterator.
		const_iterator( ) : current( nullptr )
		{ }

		// Return the object stored at the current position.
		// For const_iterator, this is an accessor with a
		// const reference return type.
		const Object & operator* ( ) const
		{ return retrieve( ); }

		const_iterator & operator++ ( )
		{
			current = current->next;
			return *this;
		}

		const_iterator operator++ ( int )
		{
			const_iterator old = *this;
			++( *this );
			return old;
		}

		const_iterator & operator-- ( )
		{
			current = current->prev;
			return *this;
		}

		const_iterator operator-- ( int )
		{
			const_iterator old = *this;
			--( *this );
			return old;
		}

		bool operator== ( const const_iterator & rhs ) const
		{ return current == rhs.current; }

		bool operator!= ( const const_iterator & rhs ) const
		{ return !( *this == rhs ); }

	protected:
		Node *current;

		// Protected helper in const_iterator that returns the object
		// stored at the current position. Can be called by all
		// three versions of operator* without any type conversions.
		Object & retrieve( ) const
		{ return current->data; }

		// Protected constructor for const_iterator.
		// Expects a pointer that represents the current position.
		const_iterator( Node *p ) :  current( p )
		{ }

		friend class doubleCList<Object>;
	};
	class iterator : public const_iterator
	{
	public:

		// Public constructor for iterator.
		// Calls the base-class constructor.
		// Must be provided because the private constructor
		// is written; otherwise zero-parameter constructor
		// would be disabled.
		iterator( )
		{ }

		Object & operator* ( )
		{ return const_iterator::retrieve( ); }

		// Return the object stored at the current position.
		// For iterator, there is an accessor with a
		// const reference return type and a mutator with
		// a reference return type. The accessor is shown first.
		const Object & operator* ( ) const
		{ return const_iterator::operator*( ); }

		iterator & operator++ ( )
		{
			this->current = this->current->next;
			return *this;
		}

		iterator operator++ ( int )
		{
			iterator old = *this;
			++( *this );
			return old;
		}

		iterator & operator-- ( )
		{
			this->current = this->current->prev;
			return *this;
		}

		iterator operator-- ( int )
		{
			iterator old = *this;
			--( *this );
			return old;
		}

	protected:
		// Protected constructor for iterator.
		// Expects the current position.
		iterator( Node *p ) : const_iterator( p ) 
		{ }

		friend class doubleCList<Object>;
	};

public:
	doubleCList()
	{
		init();
	}
	~doubleCList()
	{
		delete head;
		head = nullptr;
	}
	doubleCList(const doubleCList &rhs)
	{
		init();
		for(auto& x : rhs)
			 push_back( x );
	}
	doubleCList& operator= (const doubleCList &rhs)
	{
		doubleCList copy = rhs;
		std::swap( *this, copy );
		return *this;
	}
	//===============================================================
	// Return iterator representing beginning of list.
	// Mutator version is first, then accessor version.
	iterator begin( )
	{ return iterator( head ); }

	const_iterator begin( ) const
	{ return const_iterator( head ); }

	// Return iterator representing endmarker of list.
	// Mutator version is first, then accessor version.

	iterator end( )
	{ return iterator( head->prev ); }

	const_iterator end( ) const
	{ return const_iterator( head->prev ); }
	void PushBack(Object data)//尾插
	{
		
		Node* p = new Node(data);
		p->next = head;
		p->prev = head->prev;
		head->prev->next = p;
		head->prev = p;
		theSize++;
	}
	void PopBack()//尾删
	{
		Node* p = new Node;
		p = head->prev;

		p->prev->next = head;
		head->prev = p->prev;
		theSize--;
		delete p;
	}
	void PushFront(Object data)//头插
	{
		Node* p = new Node(data);

		p->next = head->next;
		p->prev = head;
		
		head->next->prev = p;
		head->next = p;
		theSize++;
	}
	void PopFront() //头删
	{
		Node*p = new Node;
		p = head->next;

		head->next = p->next;
		p->next->prev = head;
		theSize--;
		delete p;
	}
	void insert(Node*pos, Object data)//任意位置插入
	{
		Node* p = new Node(data);

		p->next = pos->next;
		p->prev = p;
		
		pos->next->prev = p;
		pos->next = p;
		theSize++;
	}
	void insert(iterator it, const Object& data)//任意位置插入
	{
		Node* p = it.current;

		p->next = pos->next;
		p->prev = p;

		pos->next->prev = p;
		pos->next = p;
		theSize++;
	}
	void Erase(iterator it)//任意位置删除
	{ 
		Node* p = it.current;
		p->next->prev = p->prev;
		p->prev->next = p->next;
		theSize--;
		delete p;
	}
	Node* Erase(Node* pos)//任意位置删除
	{ 
		Node* p =  pos;
		Node* temp_p = pos->next;
		p->next->prev = p->prev;
		p->prev->next = p->next;
		theSize--;
		delete p;
		return temp_p;
	}
	Node* Find(Object data)//寻找指定元素
	{
		Node* p = head;
		for(int i = 0; i < theSize; i++)
		{
			p = p->next;
			if( p->data == data )
			{
				return p;
				break;
			}
		}
		return nullptr;
	}
	void clear()//清空
	{
		Node* p = head;
		while(!Empty())
		{
			p = p->next;
			delete p;
		}
		theSize = 0;
	}
	bool Empty()	const//判断链表是否为空
	{
		return theSize==0 ;
	}
	int size()	const
	{
		return theSize;
	}
	void print()	const
	{
		Node* p = head;
		for(int i = 0; i< theSize; i++)
		{
			p = p->next;
			if(p == head)	p = p->next;
			std::cout << p->data << "	" ;
		}
		std::cout << std::endl;
	}
	// josephus问题
	void josephus()
	{
		Node* p = head->next;
		while(theSize > 1)
		{
			if(p == head)	p = p->next;
			p = p->next;
			if(p == head)	p = p->next;
			std::cout << p->data << std::endl;
			p = Erase(p);
		}
	}

private:
	Node* head;
	int theSize;
	void init()
	{
		theSize = 0;
		head = new Node();
		head->data = 0;
		head->next = head;
		head->prev = head;
	}
};

template < typename Object >
std::ostream& operator<<(std::ostream& os,const doubleCList<Object>& rhs)
{
	auto it = rhs.begin();
	while(it != rhs.end())
	{
		it++;
		os << *it << "		";
	}
}








#endif