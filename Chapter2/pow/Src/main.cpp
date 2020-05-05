/*
 * @Author: your name
 * @Date: 2020-04-01 15:57:47
 * @LastEditTime: 2020-04-01 17:24:45
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
inline bool isEven( long long x ){
    return x % 2 == 0;
}


long long Pow( long long x, int n ){
    if( n == 0 )
        return 1;
    if( n == 1 )
        return x;
    if( isEven( n ) )
        return Pow( x * x, n / 2 );
    else
        return Pow( x * x, n / 2 ) * x;    
}
int main( ){

    std::cout << gcd( 1989, 1590 ) << std::endl;
    std::cout << Pow( 2, 3 ) << "   " <<Pow( 2, 4 ) << "   " 
    << Pow( 2, 5 ) << "   " << Pow( 2, 6 ) << std::endl;

    return 0;
}