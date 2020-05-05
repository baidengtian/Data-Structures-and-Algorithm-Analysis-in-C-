/*
 * @Author: your name
 * @Date: 2020-04-02 16:56:10
 * @LastEditTime: 2020-04-02 19:27:49
 * @LastEditors: Please set LastEditors
 * @Description: Stack ÈÝÆ÷
 * @FilePath: \Stack\Src\main.cpp
 */


#include <iostream>
#include "Stack.h"
#include <vector>

int main( ){

    // std::vector<int> v;
    // v.push_back( 1 );
    // v.push_back( 2 );
    // v.push_back( 3 );

    // v.pop_back( );
    Stack<int> s;
    s.push( 1 );
    s.push( 2 );
    s.push( 3 );
    s.print( );
    s.pop( );
    int num = s.top( );
    Stack<int> s1( s );
    Stack<int> s2;
    s2 = s1;
    s2.clear( );
    return 0;
}