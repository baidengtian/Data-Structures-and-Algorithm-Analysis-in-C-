/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-04-08 20:05:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CuckooHash Table\Src\main.cpp
 */


#include <iostream>
#include <string>
#include "LeftistHeap.h"
#include <vector>

using namespace std;


int main()

{
    // int i = 10;
    // int j = 20;
    // std::cout << "&i = " << &i << "         " << "&j = " << &j << std::endl;
    // swap( i, j );
    // std::cout << "&i = " << &i << "         " << "&j = " << &j << std::endl;
    LeftistHeap<int> lh;
    lh.insert( 1 );
    lh.insert( 4 );
    lh.insert( 8 );
    lh.insert( 9 );
    lh.insert( 7 );

    LeftistHeap<int> lh2;
    lh2.insert( 2 );
    lh2.insert( 5 );
    lh2.insert( 10 );
    lh2.insert( 0 );
    lh2.insert( 99 );

    lh.merge( lh2 );
    
    lh.print( );

    int val = lh.findMin( );
    lh.deleteMin( );
    lh.deleteMin( );
    lh.makeEmpty( );
    
    LeftistHeap<int> lh1;
    lh1 = lh;
    lh1.print( );
    return 0;
}


