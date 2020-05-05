/*
 * @Author: lsyy
 * @Date: 2020-02-14 16:00:32
 * @LastEditTime: 2020-04-19 19:33:56
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Hash Table Separate Chaining\Src\main.cpp
 */
#include <iostream>
#include <string>
#include "Hash_Tab.h"
#include <vector>
#include "Employ.h"

int main()
{    
    HashTable<std::string> ht(5);
    ht.insert("bai");
    ht.insert("deng");
    ht.insert("tian");
    ht.insert("bit");
    ht.insert("cust");
    ht.insert("dw");
    ht.insert("zyy");
    ht.insert("yhy");
    ht.insert("wzx");


    // Employ employ1("bai");
    // Employ employ2("deng");
    // Employ employ3("tian");
    // Employ employ4("zhou");
    // Employ employ5("yy");
    // HashTable< Employ ,Hash_Employ > ht_employ;
    // ht_employ.insert(employ1);
    // ht_employ.insert(employ2);
    // ht_employ.insert(employ3);
    // ht_employ.insert(employ4);
    // ht_employ.insert(employ5);
    return 0;
}