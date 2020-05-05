/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-04-09 11:09:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \BinomialQueue\Src\main.cpp
 */



#include <iostream>
#include <string>
#include "BinomialQueue.h"
#include <vector>

using namespace std;


int main()

{

    BinomialQueue<int> bq;
    
    bq.insert( 1 );
    bq.insert( 2 );
    // bq.insert( 4 );
    // bq.insert( 5 );

    int size = bq.size( );

    BinomialQueue<int> bq1;
    
    bq1.insert( 6 );
    bq1.insert( 7 );
    bq1.insert( 8 );
    bq1.insert( 9 );
    bq1.insert( 10 );
    bq1.insert( 11 );
    bq1.insert( 12 );
    bq1.insert( 13 );   
    bq1.insert( 14 );
    bq1.insert( 15 );
    bq1.insert( 16 );
    bq1.insert( 17 );

    size = bq1.size( );
    
    bq.merge( bq1 );
    // BinomialQueue<int> bq2( bq );
    // BinomialQueue<int> bq3;
    // bq3 = bq;
    // bool flag = bq.isEmpty( );
    // int min_val = 0;
    // bq.deleteMin( min_val );
    // bq.makeEmpty( );
    // flag = bq.isEmpty( );


    return 0;
}


