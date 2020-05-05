/*
 * @Author: your name
 * @Date: 2020-04-01 15:57:47
 * @LastEditTime: 2020-04-01 17:05:30
 * @LastEditors: Please set LastEditors
 * @Description: 求两个数的最大公约数
 * @FilePath: \max seq\Src\main.cpp
 */
#include <iostream>

long long gcd( long long m, long long n ){
    while( n != 0 ){
        long long rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}


int main( ){

    std::cout << gcd( 1989, 1590 ) << std::endl;
    return 0;
}