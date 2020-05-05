/*
 * @Author: lsyy
 * @Date: 2020-03-21 21:57:57
 * @LastEditTime: 2020-04-06 22:02:30
 * @LastEditors: Please set LastEditors
 * @Description: treap Ê÷
 * @FilePath: \treap tree\Src\main.cpp
 */

#include <iostream>
#include "treap.h"
#include <climits>
// #include "Uniformrandom.h"

// int main( )
// {
// 	// UniformRandom r;
// 	// for( int i = 0; i < 20; ++i )
// 	// 	std::cout << r.nextInt( ) << "	";
// 	// std::cout << std::endl;
// 	Treap<int> t1;
// 	t1.insert( 1 );
// 	t1.insert( 2 );
// 	t1.insert( 5 );
// 	t1.insert( 12 );
// 	t1.insert( 6 );
// 	t1.print( );
// 	std::cout << std::endl;
// 	Treap<int> t2(t1);
// 	t2.print( );
// 	std::cout << std::endl;
// 	std::cout << std::endl;	
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	Treap<int> t3 = t1;
// 	t3.print( );
// 	std::cout << std::endl;


// 	std::cout << std::endl;
// 	std::cout << std::endl;	
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	Treap<int> t4;
// 	t4 = t1;
// 	t4.print( );
// 	std::cout << std::endl;

// 	int num = t1.findMax( );
// 	num = t1.findMin( );
	
// 	bool flag = t1.contains( 322 );
// 	flag = t1.contains( 1 );

	
// 	return 0; 
// }


#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

int main( ){
	std::set<int> s;
	s.insert( 12 );
	s.insert( 6 );
	s.insert( 1 );
	s.insert( 7 );
	s.insert( 10 );
	bool flag = s.insert( 6 ).second;
	// std::vector< std::string > sv;
	// sv.push_back( "a" );
	// sv.push_back( "na" );
	// sv.push_back( "ana" );
	// sv.push_back( "nana" );
	// sv.push_back( "anana" );
	// sv.push_back( "banana" );
	// std::sort( sv.begin( ), sv.end( ) );



	// std::string str("hello c++");
	// std::stack<char> s;
	// for( auto &c : str )
	// 	s.push( c );
	// while( !s.empty( ) ){
	// 	std::cout << s.top( );
	// 	s.pop( );
	// }




	return 0;


}
