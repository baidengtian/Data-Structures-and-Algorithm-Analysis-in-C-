/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-04-19 19:40:16
 * @LastEditors: Please set LastEditors
 * @Description: 哈希表类 ---- 分离链接法
 * @FilePath: \Hash Table\Inc\Hash_Tab.h
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
		theLists.resize(size);
		CurrentSize = 0;
	}
	// 判断 hashtable 中是否有 x 元素 
	bool contains( const HashedObj & x)	const
	{
		auto & whichList = theLists[ myhash( x ) ];
		return std::find( whichList.begin(), whichList.end(), x ) != whichList.end();
	}
	// 清空哈希表
	void makeEmpty( )
	{
		for( auto theList : theLists )
			theList.clear();
	}
	// 插入元素
	bool insert( const HashedObj & x )
	{
		auto & whichList = theLists[ myhash( x ) ];
		if( std::find( whichList.begin(), whichList.end(), x ) != whichList.end() )
			return false;
		whichList.push_back( x );
		if( ++CurrentSize > theLists.size( ) )
			rehash();
		
		return true;
	}
	// 移除元素
	bool remove( const HashedObj & x )
	{
		auto & whichList = theLists[ myhash( x ) ];
		auto itr = std::find( whichList.begin(), whichList.end(), x );

		if( itr == whichList.end() )
			return false;
		
		whichList.earse( itr );
		--CurrentSize;
		return true;
	}            
private:
	std::vector<std::list<HashedObj>> theLists;		// 链表数组
	// 元素总数
	int CurrentSize;
	// 重新散列
	void rehash( )
	{
		std::vector<std::list<HashedObj>> oldLists = theLists;
		 
		// 创建两倍大的空表
		theLists.resize( oldLists.size()*2 );
		for( auto & thisList : theLists )
			thisList.clear( );
		
		// 复制整个表
		CurrentSize = 0;

		for( auto & thisList : oldLists ) 
			for( auto & x : thisList )
				insert( x );
	}
	// 散列函数
	size_t myhash( const HashedObj & x )	const
	{
		Comparable hash;
		return hash( x ) % theLists.size();
	}

};
 

#endif 