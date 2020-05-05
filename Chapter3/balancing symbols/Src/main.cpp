/*
 * @Author: your name
 * @Date: 2020-04-02 16:56:10
 * @LastEditTime: 2020-04-02 20:07:31
 * @LastEditors: Please set LastEditors
 * @Description: Stack ÈÝÆ÷
 * @FilePath: \Stack\Src\main.cpp
 */


#include <iostream>
#include "Stack.h"
#include <vector>
#include <string>

bool BalancingSymbols( const std::string &str ){
    Stack<char> s;
    for( auto c : str ){
        if( c == '(' || c == '[' || c == '{' ){
            s.push( c );
        }
        else if( c == ')' || c == ']' || c == '}' ){
            if( s.IsEmpty( ) ){
                std::cout << " unbalancing symbols1!!! " << std::endl;
                return false;
            }
            char tmp = s.pop( );
            if( ( c == '(' && tmp != ')' )
            || ( c == '[' && tmp != ']' ) 
            || ( c == '{' && tmp != '}' )){
                std::cout << " unbalancing symbols2!!! " << std::endl;
                return false;
            }
        }
    }
    if( !s.IsEmpty( ) ){
        std::cout << " unbalancing symbols3!!! " << std::endl;
        return false;
    }
    return true;
}

int main( ){
    const std::string s{ "abd{d{[dd[dd(deekkkkkkk)]lll}" };
    bool flag = BalancingSymbols( s );
    // std::vector<int> v;
    // v.push_back( 1 );
    // v.push_back( 2 );
    // v.push_back( 3 );

    // v.pop_back( );
    // Stack<int> s;
    // s.push( 1 );
    // s.push( 2 );
    // s.push( 3 );
    // s.print( );
    // s.pop( );
    // int num = s.top( );
    // Stack<int> s1( s );
    // Stack<int> s2;
    // s2 = s1;
    // s2.clear( );
    return 0;
}