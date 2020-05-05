/*
 * @Author: your name
 * @Date: 2020-02-15 16:28:55
 * @LastEditTime: 2020-02-15 16:28:56
 * @LastEditors: Please set LastEditors
 * @Description: 产生随机数
 * @FilePath: \CuckooHash Table\Inc\UniformRandom.h
 */
#ifndef __UNIFORMRANDOM_H
#define __UNIFORMRANDOM_H

#include <iostream>
#include <chrono>
#include <cmath>
#include <random>
#include <functional>

using namespace std;

// 获得当前时间
static int currentTimeSeconds( )
{
   auto now = chrono::high_resolution_clock::now( ).time_since_epoch( );       
    return chrono::duration_cast<chrono::seconds>( now ).count( );
}



class UniformRandom
{
public:
    UniformRandom( int seed = currentTimeSeconds( ) )
    : generator( seed )
    {
    }
    // 产生一个伪随机整数
    int nextInt( )
    {
        static uniform_int_distribution<unsigned int> distribution;
        return distribution( generator );
    }
    // Return a pseudorandom int in range [0..high).
    int nextInt( int high )
    {
        return nextInt( 0, high - 1 );
    }
    // Return a pseudorandom double in the range [0..1).
    
    double nextDouble( )
    {
        static uniform_real_distribution<double> distribution( 0, 1 );
        return distribution( generator );
    }
    // Return an int in the closed range [low,high].
    int nextInt( int low, int high )
    {
        uniform_int_distribution<int> distribution( low, high );
        return distribution( generator );
    }
    
private:
    mt19937 generator;
};













#endif