/*
 * @Author: lsyy
 * @Date: 2020-03-12 20:38:10
 * @LastEditTime: 2020-03-12 21:08:48
 * @LastEditors: Please set LastEditors
 * @Description: 动态规划案例
 * @FilePath: \dynamic programmig\Src\main.cpp
 */


#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <vector>
#include <climits>


int exchange( int amount, std::vector<int> coins )
{
    if( amount == 0 )       // 钱刚好凑完
        return 0; 

    if( amount < 0 )        // 没有满足的条件
        return -1;
    
    int result = INT_MAX;

    for( auto x : coins )
    {
        int SubMin = exchange( amount - x, coins );
        if( SubMin == -1 )
            continue;
        result = std::min( SubMin + 1 , result );
    }

    if( result == INT_MAX )
        return -1;

    return result; 
}


int main( )
{
    int amount = 11;
    std::vector<int> coins;
    coins.push_back( 1 );
    coins.push_back( 2 );
    coins.push_back( 5 );
    std::cout << exchange( amount, coins ) << std::endl;
    return 0;
}


