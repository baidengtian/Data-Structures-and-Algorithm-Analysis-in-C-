/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime : 2020-02-14 17:35:57
 * @LastEditors  : Please set LastEditors
 * @Description: ��ϣ�� ---- ����̽�뷨������ͻ
 * @FilePath: \Hash Table Quadratic Probing\Inc\Hash_Tab.h
 */

#ifndef __HASH_TABLE_H                                                                                                                                                                                                                                                                                                                                                     
#define __HASH_TABLE_H

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>

// Ĭ�ϵ�ɢ�к���
class hash 
{
public:
	size_t operator( )( const std::string & k )
	{
		size_t hashVal = 0;
		for( char ch : k )
			hashVal = 37 * hashVal + ch;
		return hashVal;
	}

};
template < typename HashedObj, typename Comparable = hash >
class HashTable
{
public:
	explicit HashTable( int size = 101 ) 
	{
		arry.resize( size );
		makeEmpty();
	}
	// �ж� hashtable ���Ƿ��� x Ԫ�� 
	bool contains( const HashedObj & x)	const
	{
		return isActive( findPos( x ) );
	}
	// ��չ�ϣ��
	void makeEmpty( )
	{
		CurrentSize = 0;
		for( auto & entry : arry )
			entry.info = EMPTY;
	}
	// ����Ԫ��
	bool insert( const HashedObj & x )
	{
		int currentPos = findPos( x );
		if( isActive( currentPos ) )			// ��Ԫ�����ڹ�ϣ���в���״̬ΪACTIVE
			return false;

		arry[ currentPos ].element = x;			// ��Ԫ�ز��ڹ�ϣ���� ���� ����״̬ ACTIVE
		arry[ currentPos ].info = ACTIVE;

		if( ++CurrentSize > arry.size() / 2 )	// �����ϣ��Ԫ�ش���1/2��Ĵ�С ����ɢ��
			rehash( );
		return true;
	}
	// �Ƴ�Ԫ��
	bool remove( const HashedObj & x )
	{
		int currentPos = findPos( x );
		if( !isActive( currentPos ) )
			return false;
		arry[ currentPos ].info = DELETED;		// ����ɾ��
		return true;
	}   
	enum EntryType { ACTIVE, EMPTY, DELETED };        
private:
	struct HashEntry
	{
		HashedObj element;
		EntryType info;
		HashEntry( const HashedObj & e = HashedObj(), EntryType i = EMPTY )
		: element( e ), info( i ) 
		{

		}
	};
	std::vector< HashEntry > arry;		// �洢��ϣ�������
	// Ԫ������
	int CurrentSize;
	// ����ɢ��
	void rehash( )
	{
		std::vector<HashEntry> oldArray = arry;
		// �������󵽶���
		arry.resize( 2 * oldArray.size() );
		for( auto & entry : arry )
			entry.info = EMPTY;
		// ����������
		CurrentSize = 0;
		for( auto & entry : oldArray )
			if( entry.info == ACTIVE )
				insert( entry.element );
	}
	// ���� currentPos λ���Ƿ���Ԫ��
	bool isActive( int currentPos )	const
	{
		return arry[currentPos].info == ACTIVE;
	}
	// ���� x Ԫ�ص�λ��
	int findPos( const HashedObj & x )	const
	{
		int offest = 1;
		int currentPos = myhash( x );
		while ( arry[currentPos].info != EMPTY && arry[currentPos].element != x  )
		{
			currentPos += offest;			// �����i��̽�� f(i) = i^2   =>  f(i) = f(i-1) + i-1
			offest += 2;					// 						ƽ�����⺯��
			if( currentPos > arry.size() )
				currentPos -= arry.size(); 
		}
		return currentPos;
	}
	// ɢ�к���
	size_t myhash( const HashedObj & x )	const
	{
		Comparable hash;
		return hash( x ) % arry.size();
	}
};
 

#endif 