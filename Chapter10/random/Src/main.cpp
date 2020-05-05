/*
 * @Author: your name
 * @Date: 2020-03-14 17:55:09
 * @LastEditTime: 2020-03-14 20:15:44
 * @LastEditors: Please set LastEditors
 * @Description: 产生随机数
 * @FilePath: \random\Src\main.cpp
 */

#include "random.h"
#include <iostream>


int main( )
{
	random r;

	for( int i = 0; i < 100; ++i )
	{
		std::cout << r.randomInt( 1, 1000 ) << "   ";
		if( i % 10 == 0 )	std::cout << std::endl;
	}
	return 0;
}