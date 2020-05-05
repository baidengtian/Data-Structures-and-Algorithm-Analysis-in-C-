/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-02-15 16:04:35
 * @LastEditors: Please set LastEditors
 * @Description: �ž�ɢ��
 * @FilePath: \CuckooHash Table\Inc\CuckooHash_Tab.h
 */

#ifndef __CUCKOOHASH_TABLE_H                                                                                                                                                                                                                                                                                                                                                     
#define __CUCKOOHASH_TABLE_H

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include "UniformRandom.h"
#include <cstdlib>
#define MAX_LOAD 0.40


template < typename AnyType, typename HashFamily >
class CuckooHashTable
{
public:
	explicit CuckooHashTable( int size = 101 ) 
	{
		array.resize( size );
		numHashFunctions = hashFunctions.getNumberOfFunctions( );
		rehashes = 0;
		makeEmpty( );
	}
	// ��չ�ϣ��
	void makeEmpty( )
	{
		// ֱ��ɾ�� ��������ɾ��
		currentSize = 0;
		for( auto & entry : array )
			entry.isActive = false;
	}
	// �ж�Ԫ�� x �Ƿ��ڹ�ϣ����
	bool contains( const AnyType & x )	const
	{
		return findPos( x ) != -1;
	}
	// �Ƴ�Ԫ�� x
	bool remove( const AnyType & x )
	{
		int currentPos = findPos( x );
		if( !isActive( currentPos ) )
			return false;
		// ֱ��ɾ��Ԫ��
		array[ currentPos ].isActive = false;
		--currentSize;
		return true;
	}
	// ����Ԫ�� x 
	bool insert( const AnyType & x )
	{
		if( contains( x ) )
			return false;
		if( currentSize > array.size() * MAX_LOAD )
			expand();

		return insertHelperl( x );
	}
	void print( )	const
	{
		for( auto entry : array )
			if( entry.isActive )
				std::cout << entry.element << std::endl;
	}
	int size( ) const
    {
        return currentSize;
    }
    
    int capacity( ) const
    {
        return array.size( );
    }
private:
	struct HashEntry
	{
		AnyType element;
		bool isActive;
		HashEntry( const AnyType & e = AnyType(), bool a = false )
		: element( e ), isActive( a )
		{
		}
	};
	// ����ľ������
	bool insertHelperl( const AnyType & xx ){

		const int COUNT_LIMIT = 100;
		AnyType x = xx;

		while( true ){
			int lastPos = -1;
			int pos;
			for( int count = 0; count < COUNT_LIMIT; ++count ){
				// ��γ��Ը�����ϣ����
				for( int i = 0; i < numHashFunctions; ++i ){
					pos = myhash( x, i );
					if( !isActive( pos ) ){
						array[ pos ] = HashEntry(x,true);
						++currentSize;
						return true;
					}
				}
				// �޿���λ�ã����һ���漴��
				int i = 0;
				do{
					pos = myhash( x, r.nextInt( numHashFunctions ) );
				}while( pos == lastPos && i++ < 5 );

				lastPos = pos;
				std::swap( x, array[ pos ].element );

			}
			if( ++rehashes > ALLOWED_REHASHS ){
				expand( );					// ʹ��ϣ������
				rehashes = 0;				// ����rehashes�ļ���
			}
			else 
				rehash( );					// ��Ĵ�С��ͬ����ϣ���������µ�
		}
	}
	bool isActive( int currentPos )	const
	{
		return array[ currentPos ].isActive;
	}
	// ʹ���ض���������x�Ĺ�ϣֵ
	size_t myhash( const AnyType & x, int which )	const
	{
		return hashFunctions.hash( x, which ) % array.size( );
	}
	// ����ɢ�к���λ��
	int findPos( const AnyType & x )	const
	{
		for( int i = 0; i < numHashFunctions; ++i )
		{
			int pos = myhash( x, i );
			if( isActive( pos ) && array[ pos ].element == x )
				return pos;
		}
		return -1;
	}
	void expand( )  
	{
		rehash( static_cast<int> ( array.size() / MAX_LOAD ) );
	}
	// ������ϣ���� ���¼����ϣֵ
	void rehash( )
	{
		// �������ɹ�ϣ����
		hashFunctions.generateNewFunctions( );
		rehash( array.size( ) );
	}
	// �ı��ϣ��Ĵ�С ���¼����ϣֵ
	void rehash( int newSize )
	{
		std::vector<HashEntry> oldArry = array;
		// �����µ�������С�Ĺ�ϣ��
		array.resize( newSize );
		for( auto & entry : array )
			entry.isActive = false;
		
		// ����������ϣ��
		currentSize = 0;
		for( auto & entry : oldArry )
			if( entry.isActive )
				insert( entry.element );
	}
	// static const double MAX_LOAD = 0.40;
	static const int ALLOWED_REHASHS = 5;
	
	std::vector<HashEntry> array;						// ��ϣ��
	int currentSize;									// ��ϣ��ǰԪ�ظ���
	int numHashFunctions;								// ��ϣ��������
	int rehashes;										// ���� hash �Ĵ��� ����hash�����صĴ���
	UniformRandom r;									// ����������Ķ���
	HashFamily hashFunctions;							// ��ϣ������
};

#endif 