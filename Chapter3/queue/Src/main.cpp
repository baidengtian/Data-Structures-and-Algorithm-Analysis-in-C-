/*
 * @Author: your name
 * @Date: 2020-04-03 16:31:28
 * @LastEditTime: 2020-04-04 11:39:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \queue\Src\main.cpp
 */


#include <iostream>
#include "Queue.h"


int main( ){

    Queue<int> q( 5 );
    int size = q.capacity( );
    q.enqueue( 1 );
    size = q.capacity( );
    q.enqueue( 2 );
    size = q.capacity( );
    q.enqueue( 3 );
    size = q.capacity( );
    q.print( );
    q.enqueue( 4 );
    q.enqueue( 5 );
    // int num = q.dequeue( );
    // num = q.dequeue( );
    // num = q.dequeue( );
    q.enqueue( 6 );
    q.enqueue( 7 );
    q.dequeue( );
    q.dequeue( );
    q.dequeue( );
    q.dequeue( );
    q.dequeue( );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );
    q.enqueue( 12 );

    q.print( );
    return 0;
}




 