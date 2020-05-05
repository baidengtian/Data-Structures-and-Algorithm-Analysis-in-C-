/*
 * @Author: lsyy
 * @Date: 2020-04-01 15:57:47
 * @LastEditTime: 2020-04-01 21:39:12
 * @LastEditors: Please set LastEditors
 * @Description: Vector µÄÈÝÆ÷ÊµÏÖ
 * @FilePath: \max seq\Src\main.cpp
 */
#include <iostream>
#include "Vector.h"


int main( ){

    Vector<int> iv;
    iv.push_back( 1 );
    iv.push_back( 2 );
    iv.push_back( 3 );

    iv.print( );

    Vector<int> iv2;
    iv2 = iv;
    iv2.print( );

    iv2.pop_back( );

    iv2.print( );
    return 0;
}