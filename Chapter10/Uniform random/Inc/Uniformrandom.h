/*
 * @Author: your name
 * @Date: 2020-03-14 17:55:09
 * @LastEditTime: 2020-03-14 21:37:39
 * @LastEditors: Please set LastEditors
 * @Description: 产生随机数类
 * @FilePath: \random\Inc\random.h
 */

#pragma 

#include <chrono>
#include <random>
#include <functional>

using namespace std;

static int currentTimeSeconds( )
{
    auto now  = chrono::high_resolution_clock::now( ).time_since_epoch( );
    return ( chrono::duration_cast<chrono::seconds>( now ) ).count( );
}

class UniformRandom
{
public:
    UniformRandom( int seed = currentTimeSeconds( ) ) : generator { seed }
    {

    }
    // 返回一个伪随机的 int
    int nextInt( )
    {
        static uniform_int_distribution< unsigned int > distribution;
        return distribution( generator );
    }
    // 返回一个在范围 [ 0..high ) 之间的伪随机的 int
    int nextInt( int high ) 
    {
        return nextInt( 0, high - 1 );
    }
    // 返回一个范围在 [ low..high ]之间的伪随机 int 
    int nextInt( int low, int high )
    {
        uniform_int_distribution<int> distribution( low, high );
        return distribution( generator );
    }
    // 返回一个在范围 [ 0..1 ) 之间的伪随机的 double 
    double nextDouble( )
    {
        static uniform_real_distribution<double> distribution( 0, 1 );
        return distribution( generator );
    }
private:
    mt19937 generator;
};
 