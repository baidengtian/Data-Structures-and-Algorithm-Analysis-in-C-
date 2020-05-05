/*
 * @Author: your name
 * @Date: 2019-05-31 22:13:05
 * @LastEditTime : 2020-01-02 20:45:36
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CPP_DEMO\helloworld.cpp
 */
#include <iostream>
#include <string>
#include "test.h"


template<typename Iterator,typename Object>
Iterator Find (Iterator start, Iterator end, const Object & x)
{
    for(; start != end; start++)
    {
        if(*start == x)
            return start;
    }
}

int main()
{
    List<int> l1;
    l1.push_back(5);
    l1.push_back(6);
    l1.push_front(1);
    List<int>::iterator it = l1.begin();

    while (it != l1.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }

    auto it2 = Find(l1.begin(),l1.end(),6);
    std::cout << "I find " << *it2 << std::endl;

    return 0;
}