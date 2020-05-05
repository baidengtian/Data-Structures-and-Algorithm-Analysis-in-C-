/*
 * @Author: your name
 * @Date: 2020-04-02 19:29:10
 * @LastEditTime: 2020-04-04 12:26:01
 * @LastEditors: Please set LastEditors
 * @Description: Stack 后缀表达式
 * @FilePath: \Stack\Src\main.cpp
 */


#include <iostream>
#include <string>
#include "ExpressionTree.h"



int main( ){

    ExpressionTree<char> t;
    std::string str("ab+cde+**");
    t.CreateExpTree( str );
    t.print( );
    return 0;
}