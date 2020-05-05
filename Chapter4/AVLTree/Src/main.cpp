/*
 * @Author: lsyy
 * @Date: 2020-02-09 20:03:44
 * @LastEditTime: 2020-04-04 22:04:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \AVLTree\Src\main.cpp
 */
#include <iostream>
#include <string>
#include "AVLTree.h"
int main()
{    
    
    AVLTree<int> tree;
    // // RR �Ͳ���
    // tree.insert(4);
    // tree.insert(5);
    // tree.insert(6);
    
    // // LL �Ͳ���
    // tree.insert(6);
    // tree.insert(5);
    // tree.insert(4);
    

    // // LR �Ͳ���
    // tree.insert(3);
    // tree.insert(1);
    // tree.insert(2);

    // RL �Ͳ���
    tree.insert(3);
    tree.insert(6);
    tree.insert(5);
    
    AVLTree<int> tree2(tree);
    
    AVLTree<int> tree3; 
    tree3 = tree;

    tree3.makeEmpty();
    bool flag = tree3.isEmpty();
    
    flag = tree.contains(3);

    int num = tree.findMax();
    num = tree.findMin();
    tree.BFSOrder( );
    return 0;
}