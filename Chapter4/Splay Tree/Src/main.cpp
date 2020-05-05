/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime : 2020-02-12 21:39:04
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Splay Tree\Src\main.cpp
 */

#include <iostream>
#include <string>
#include "SplayTree.h"
int main()
{    
    SplayTree<int> tree;
    tree.insert(7);
    tree.insert(6);
    tree.insert(10);
    tree.insert(20);
    tree.insert(2);
    tree.printTree();
    tree.remove(20);
    int num = tree.findMax();
    num = tree.findMin();
    
    SplayTree<int> tree2( tree );
    
    SplayTree<int> tree3;
    tree3 = tree2;
    
    tree.makeEmpty();
    return 0;
}