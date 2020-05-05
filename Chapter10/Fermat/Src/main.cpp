/*
 * @Author: your name
 * @Date: 2020-03-14 17:55:09
 * @LastEditTime: 2020-03-15 11:54:19
 * @LastEditors: Please set LastEditors
 * @Description: 产生随机数
 * @FilePath: \random\Src\main.cpp
 */
#include <iostream>
#include "Uniformrandom.h"
#include <cmath>
typedef long long int HugeInt;

HugeInt witness( const HugeInt & a, const HugeInt & i, const HugeInt & n )
{
	if( i == 0 )
		return 1;
	HugeInt x = witness( a, i / 2, n );
	if( x == 0 )
		return 0;
	HugeInt y = ( x * x ) % n;
	if( y == 1 && x != 1 && x != n - 1 )
		return 0;
	if( i % 2 != 0 )
		y = ( a * y ) % n;
	
	return y;
}
const int TRIALS = 50;

bool isPrime( const HugeInt & n )
{
	UniformRandom r;
	
	for( int counter = 0; counter < TRIALS; ++counter )
	{
		HugeInt val = r.nextHugeInt( 2, n - 2 );
		if( witness( val, n - 1, n ) != 1 )
			return false;
	}

	return true;
}



int main( )
{
	HugeInt num = 1010107;
	bool flag = isPrime( num );
	for( HugeInt i = 1; i < num; ++i )
	{
		if( num % i ==0 )	std::cout << i << std::endl;
	}
	return 0;
}