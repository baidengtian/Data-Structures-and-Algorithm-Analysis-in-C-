/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime : 2020-02-14 17:37:02
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Hash Table\Src\main.cpp
 */
/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime : 2020-02-14 09:52:02
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Splay Tree\Src\main.cpp
 */

#include <iostream>
#include <string>
#include "Hash_Tab.h"
#include <vector>
#include "Employ.h"
int main()
{    
    HashTable<std::string> ht(13);
    ht.insert("bai");
    ht.insert("deng");
    ht.insert("tian");
    ht.insert("bit");
    ht.insert("cust");
    ht.insert("dw");
    ht.insert("zhou");
    ht.insert("yy");
    ht.insert("yhy");
    ht.remove("wzx");
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