/*
 * @Author: lsyy
 * @Date: 2020-02-09 20:03:44
 * @LastEditTime: 2020-04-22 11:32:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Binary Search Tree\Src\main.cpp
 */
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
int main()
{    
    
    BinarySearchTree<int> tree;
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(0);
    tree.insert(-1);
    tree.insert(9); 
    tree.insert(10);

    int nodesnum = tree.CountNodesTail( );

    tree.remove(2);

    bool flag = tree.contains(0);

    int num = tree.findMax();
    num = tree.findMin();

    BinarySearchTree<int> tree2;
    tree2 = tree;
    tree.makeEmpty();
    flag = tree.isEmpty();

    // ≤‚ ‘¥Ú”°∫Ø ˝
    BinarySearchTree<int> tree3;
    tree3.insert(4);
    tree3.insert(3);
    tree3.insert(1);
    tree3.insert(5);
    tree3.MidPrintTree();
    std::cout << std::endl << std::endl;
    tree3.ProPrintTree();
    std::cout << std::endl << std::endl;
    tree3.LastPrintTree();
    std::cout << std::endl << std::endl;

    return 0;
}