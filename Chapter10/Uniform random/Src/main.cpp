/*
 * @Author: your name
 * @Date: 2020-03-14 17:55:09
 * @LastEditTime: 2020-03-14 21:31:06
 * @LastEditors: Please set LastEditors
 * @Description: 产生随机数
 * @FilePath: \random\Src\main.cpp
 */

#include "Uniformrandom.h"
#include <iostream>


int main( )
{
	UniformRandom r;

	for( int i = 0; i < 100; ++i )
	{
		if( i % 10 == 0 )	std::cout << std::endl;
		std::cout << r.nextInt( 1, 1000 ) << "   ";
	}
	return 0;
}