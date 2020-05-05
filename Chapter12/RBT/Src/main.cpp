/*
 * @Author: your name
 * @Date: 2020-03-19 21:20:01
 * @LastEditTime: 2020-03-23 17:01:21
 * @LastEditors: Please set LastEditors
 * @Description: ºìºÚÊ÷Àà
 * @FilePath: \RedBlackTree\Src\main.cpp
 */


#include <iostream>
#include <RedBlackTree.h>
#include <climits>

int main( )
{
	RedBlackTree<int> t;
	t.insert( 1 );
	t.insert( 22 );
	t.insert( 3 );
	t.insert( 14 );
	t.insert( 11 );
	t.insert( 9 );
	t.insert( 81 );
	t.remove( 1 );
	t.inorder( );
	return 0; 
}
