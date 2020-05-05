/*
 * @Author: lsyy
 * @Date: 2020-03-15 11:04:10
 * @LastEditTime: 2020-03-16 10:17:47
 * @LastEditors: Please set LastEditors
 * @Description: �շѹ�·�ؽ�����
 * @FilePath: \Turnpike reconstruction algorithm\Src\main.cpp
 */

#include <iostream>
#include "Uniformrandom.h"
#include <cmath>
#include <vector>
#include <algorithm>

inline bool remove( std::vector<int> & v, int elem )
{
	std::vector<int>::iterator itor = std::find( v.begin( ), v.end( ), elem );
	if( itor != v.end( ) )
	{
		v.erase( itor );	
		return true;
	}
	else
		return false;

}

bool place( std::vector<int> & x, std::vector<int> & d, int n, int left, int right )
{
	// std::cout << "ok" << std::endl;
	int dmax = 0;
	bool found = false;

	if( d.empty( ) )
		return true;
	
	dmax = *( --d.end( ) );					// ���������һ��������������

	bool state = true;
	std::vector<int> deletetable;
	// ��֤ x[ right ] = dmax �Ƿ����
	for( int j = 0; j < left; ++j )
	{
		if( std::find( d.begin( ), d.end( ), abs( x[ j ] - dmax ) ) != d.end( ) )
			deletetable.push_back( abs( x[ j ] - dmax ) );
		else
		{
			state = false;
			break;
		}
	}
	for( int j = right + 1; j <= n; ++j )
	{
		if( std::find( d.begin( ), d.end( ), abs( x[ j ] - dmax ) ) != d.end( ) )
			deletetable.push_back( abs( x[ j ] - dmax ) );
		else
		{
			state = false;
			break;
		}
	}
	if( state )
	{
		x[ right ] = dmax;							// ���� x[ right ] = dmax
		for( auto x : deletetable )
			if( !remove( d, x ) ) 
			{
				remove( deletetable, x );
				found = false;
			}


		found = place( x, d, n, left, right - 1 );
		if( !found )								// ����
		{
			for( auto elem : deletetable )
				d.push_back( elem );				// ����ɾ��
			std::sort( d.begin( ), d.end( ) );
		}
	}
	// �����һ������ʧ�� ����ͼ�鿴
	// ��֤ x[ left ] = x[ n ] - dmax�Ƿ���� 
	if( !found  )
	{
		state = true;
		deletetable.erase( deletetable.begin( ), deletetable.end( ) );
		for( int j = 0; j < left; ++j )
		{
			if( std::find( d.begin( ), d.end( ), abs( x[n] - x[ j ] - dmax ) ) != d.end( ) )
				deletetable.push_back( abs( x[ n ] - x[ j ] - dmax ) );
			else
			{
				state = false;
				break;
			}
		}
		for( int j = right + 1; j <= n; ++j )
		{
			if( std::find( d.begin( ), d.end( ), abs( x[n] - x[ j ] - dmax ) ) != d.end( ) )
				deletetable.push_back( abs( x[ n ] - x[ j ] - dmax ) );
			else
			{
				state = false;
				break;
			}
		}
	}
	if( !found && state )
	{
		x[ left ] = abs( x[ n ] - dmax );			// ���� x[ left ] = x[ n ] - dmax
		for( auto x : deletetable )
			if( !remove( d, x ) )	
			{
				remove( deletetable, x );
				found = false;
			}

		found = place( x, d, n, left + 1, right );
		if( !found )
		{
			for( auto elem : deletetable )
				d.push_back( elem );
			std::sort( d.begin( ), d.end( ) );
		}
	}
	return found;
}
/**
 * @description: �շѹ�·�ؽ�������������
 * @param {type} x ��� �շ�վ�������� d ������������������� n ���շ�վ
 * @return: �����н� true
 */
bool turnpile( std::vector<int> & x, std::vector<int> & d, int n )
{
	x[ 0 ] = 0;
	std::sort( d.begin( ), d.end( ) );
	
	x[ n - 1 ] = *( --d.end( ) );				// �����½Ǳ� 0 ��ʼ
	x[ n - 2 ] = *(--( --d.end( ) ));			// STL �� end( ) ָ�����һ��Ԫ�ص���һ��λ��
 
	d.pop_back( );
	d.pop_back( );
	
	if( remove( d, x[ n - 1 ] - x[ n - 2 ] ) )
		place( x, d, n - 1, 1, n - 3 );
	else
		return false;

	return true;

}

int main( )
{
	int distance[] = { 1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 6, 7, 8, 10 };
	std::vector< int > d( distance, distance + sizeof(distance) / sizeof( distance[ 0 ] ) );
	std::vector< int > x( 6, 0 );
	bool result = turnpile( x, d, 6 );
	return 0;
}