#ifndef __SINGLELIST_H
#define __SINGLELIST_H


#include <iostream>

template < typename Object >
class singleList
{
//===============================================================

	struct Node
	{
		Object data;
		Node* next;
		Node( const Object & d = Object(),Node * n = nullptr )
			: data( d ), next( n ) { }

		Node( Object && d, Node * n = nullptr )
			: data( std::move( d ) ), next( n ) { }
	};
//===============================================================

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

		bool operator== ( const const_iterator & rhs ) const
		{ return current == rhs.current; }

		bool operator!= ( const const_iterator & rhs ) const
		{ return !( *this == rhs ); }

		// protected:
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

		friend class singleList<Object>;
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

	protected:
		// Protected constructor for iterator.
		// Expects the current position.
		iterator( Node *p ) : const_iterator( p )
		{ }

		friend class singleList<Object>;
	};
//===============================================================

public:
	singleList()
	{
		init();
	}
	singleList(const singleList& rhs)
	{

	}
	singleList& operator = (const singleList& rhs)
	{

	}
	~singleList()
	{
		delete head;
		head = nullptr;
	}
	int size()	const
	{
		return theSize;
	}
	iterator begin()
	{
		return iterator(head);
	}
	iterator push_back( const Object& rhs )
	{
		return insert(begin(),rhs);
	}
	iterator insert(iterator pos, const Object& rhs)
	{

		auto it = begin();		
		while(it != pos)
		{
			it++;
		}
 		Node *p = it.current;
		p->next = new Node(rhs);
		// p->next->data = rhs;
		p->next->next = it.current->next->next;
		theSize++;
		return it++;
	}
	void print()	const
	{
		Node *p = head;
		for(int i = 0; i < theSize; i++)
		{
			p = p->next;
			std::cout << p->data << std::endl;
		}
	}
private:
	Node* head;
	int theSize;
	void init()
	{
		theSize = 0;
		head = new Node;
	}

};









#endif