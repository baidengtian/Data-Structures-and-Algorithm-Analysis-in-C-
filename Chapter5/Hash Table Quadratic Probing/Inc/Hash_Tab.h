/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime : 2020-02-14 17:35:57
 * @LastEditors  : Please set LastEditors
 * @Description: 哈希表 ---- 二次探针法消除冲突
 * @FilePath: \Hash Table Quadratic Probing\Inc\Hash_Tab.h
 */

#ifndef __HASH_TABLE_H                                                                                                                                                                                                                                                                                                                                                     
#define __HASH_TABLE_H

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>

// 默认的散列函数
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
	// 判断 hashtable 中是否有 x 元素 
	bool contains( const HashedObj & x)	const
	{
		return isActive( findPos( x ) );
	}
	// 清空哈希表
	void makeEmpty( )
	{
		CurrentSize = 0;
		for( auto & entry : arry )
			entry.info = EMPTY;
	}
	// 插入元素
	bool insert( const HashedObj & x )
	{
		int currentPos = findPos( x );
		if( isActive( currentPos ) )			// 该元素已在哈希表中并且状态为ACTIVE
			return false;

		arry[ currentPos ].element = x;			// 该元素不在哈希表中 插入 激活状态 ACTIVE
		arry[ currentPos ].info = ACTIVE;

		if( ++CurrentSize > arry.size() / 2 )	// 如果哈希表元素大于1/2表的大小 重新散列
			rehash( );
		return true;
	}
	// 移除元素
	bool remove( const HashedObj & x )
	{
		int currentPos = findPos( x );
		if( !isActive( currentPos ) )
			return false;
		arry[ currentPos ].info = DELETED;		// 懒惰删除
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
	std::vector< HashEntry > arry;		// 存储哈希表的数组
	// 元素总数
	int CurrentSize;
	// 重新散列
	void rehash( )
	{
		std::vector<HashEntry> oldArray = arry;
		// 容量扩大到而被
		arry.resize( 2 * oldArray.size() );
		for( auto & entry : arry )
			entry.info = EMPTY;
		// 复制整个表
		CurrentSize = 0;
		for( auto & entry : oldArray )
			if( entry.info == ACTIVE )
				insert( entry.element );
	}
	// 查找 currentPos 位置是否含有元素
	bool isActive( int currentPos )	const
	{
		return arry[currentPos].info == ACTIVE;
	}
	// 查找 x 元素的位置
	int findPos( const HashedObj & x )	const
	{
		int offest = 1;
		int currentPos = myhash( x );
		while ( arry[currentPos].info != EMPTY && arry[currentPos].element != x  )
		{
			currentPos += offest;			// 计算第i次探测 f(i) = i^2   =>  f(i) = f(i-1) + i-1
			offest += 2;					// 						平方消解函数
			if( currentPos > arry.size() )
				currentPos -= arry.size(); 
		}
		return currentPos;
	}
	// 散列函数
	size_t myhash( const HashedObj & x )	const
	{
		Comparable hash;
		return hash( x ) % arry.size();
	}
};
 

#endif 