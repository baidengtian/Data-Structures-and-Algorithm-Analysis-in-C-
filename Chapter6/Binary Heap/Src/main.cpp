/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-02-17 20:14:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CuckooHash Table\Src\main.cpp
 */


#include <iostream>
#include <string>
#include "BinaryHeap.h"
#include <vector>

using namespace std;


int main()
{

    BinaryHeap<int> bh(3);
    bh.insert(10);
    bh.insert(19);
    bh.insert(70);
    bh.insert(6);
    bh.insert(100);
    bh.insert(101);
    bh.insert(110);
    bh.print( );
    std::cout << "-------------------------------------------------------" << std::endl;
    bh.deleteMin( );
    bh.print( );
    return 0;
}


