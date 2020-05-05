/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-02-15 16:04:35
 * @LastEditors: Please set LastEditors
 * @Description: 杜鹃散列
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
	// 清空哈希表
	void makeEmpty( )
	{
		// 直接删除 不是懒惰删除
		currentSize = 0;
		for( auto & entry : array )
			entry.isActive = false;
	}
	// 判断元素 x 是否在哈希表中
	bool contains( const AnyType & x )	const
	{
		return findPos( x ) != -1;
	}
	// 移除元素 x
	bool remove( const AnyType & x )
	{
		int currentPos = findPos( x );
		if( !isActive( currentPos ) )
			return false;
		// 直接删除元素
		array[ currentPos ].isActive = false;
		--currentSize;
		return true;
	}
	// 插入元素 x 
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
	// 插入的具体操作
	bool insertHelperl( const AnyType & xx ){

		const int COUNT_LIMIT = 100;
		AnyType x = xx;

		while( true ){
			int lastPos = -1;
			int pos;
			for( int count = 0; count < COUNT_LIMIT; ++count ){
				// 逐次尝试各个哈希函数
				for( int i = 0; i < numHashFunctions; ++i ){
					pos = myhash( x, i );
					if( !isActive( pos ) ){
						array[ pos ] = HashEntry(x,true);
						++currentSize;
						return true;
					}
				}
				// 无可用位置，逐出一个随即项
				int i = 0;
				do{
					pos = myhash( x, r.nextInt( numHashFunctions ) );
				}while( pos == lastPos && i++ < 5 );

				lastPos = pos;
				std::swap( x, array[ pos ].element );

			}
			if( ++rehashes > ALLOWED_REHASHS ){
				expand( );					// 使哈希表扩大
				rehashes = 0;				// 重置rehashes的计数
			}
			else 
				rehash( );					// 表的大小相同，哈希函数都是新的
		}
	}
	bool isActive( int currentPos )	const
	{
		return array[ currentPos ].isActive;
	}
	// 使用特定函数计算x的哈希值
	size_t myhash( const AnyType & x, int which )	const
	{
		return hashFunctions.hash( x, which ) % array.size( );
	}
	// 查找散列函数位置
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
	// 跟换哈希函数 重新计算哈希值
	void rehash( )
	{
		// 重新生成哈希函数
		hashFunctions.generateNewFunctions( );
		rehash( array.size( ) );
	}
	// 改变哈希表的大小 重新计算哈希值
	void rehash( int newSize )
	{
		std::vector<HashEntry> oldArry = array;
		// 创建新的两倍大小的哈希表
		array.resize( newSize );
		for( auto & entry : array )
			entry.isActive = false;
		
		// 复制整个哈希表
		currentSize = 0;
		for( auto & entry : oldArry )
			if( entry.isActive )
				insert( entry.element );
	}
	// static const double MAX_LOAD = 0.40;
	static const int ALLOWED_REHASHS = 5;
	
	std::vector<HashEntry> array;						// 哈希表
	int currentSize;									// 哈希表当前元素个数
	int numHashFunctions;								// 哈希函数个数
	int rehashes;										// 重新 hash 的次数 更换hash函数簇的次数
	UniformRandom r;									// 产生随机数的对象
	HashFamily hashFunctions;							// 哈希函数簇
};

#endif 