/*
 * @Author: your name
 * @Date: 2019-05-31 22:13:05
 * @LastEditTime : 2020-01-02 16:27:07
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CPP_DEMO\helloworld.cpp
 */
#include <iostream>
#include <string>
#include "helloworld.h"



using namespace std;

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

    it = l1.begin();


    it++;

    l1.swap(it.current);

    it = l1.begin();
    while (it != l1.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    return 0;
}