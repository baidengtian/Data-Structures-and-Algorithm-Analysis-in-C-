/*
 * @Author: your name
 * @Date: 2019-05-31 22:13:05
 * @LastEditTime : 2020-01-02 21:06:41
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CPP_DEMO\helloworld.cpp
 */
#include <iostream>
#include <string>
#include "test.h"

/**
 * @description: 求两个链表的交集
 * @param {type} l1 链表1 l2 链表2
 * @return: null
 */
template <typename Object>
void Intersection(List<Object>* l1,List<Object> l2)
{
    for(auto it2 = l2.begin(); it2 != l2.end(); it2++)
    {
        bool flag = false;
        for(auto it1 = l1->begin(); it1 != l1->end(); it1++)
            if(*it1 == *it2)    
            {
                flag = true;
                break;
            }
               
        if(!flag)    l1->push_back(*it2);
    }
}
int main()
{
    List<int> l1;
    l1.push_back(5);
    l1.push_back(6);
    l1.push_front(1);

    List<int> l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_front(3);


    Intersection(&l1, l2);

    List<int>::iterator it = l1.begin();

    while (it != l1.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }


    return 0;
}