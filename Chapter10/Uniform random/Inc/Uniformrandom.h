/*
 * @Author: your name
 * @Date: 2020-03-14 17:55:09
 * @LastEditTime: 2020-03-14 21:37:39
 * @LastEditors: Please set LastEditors
 * @Description: �����������
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
    // ����һ��α����� int
    int nextInt( )
    {
        static uniform_int_distribution< unsigned int > distribution;
        return distribution( generator );
    }
    // ����һ���ڷ�Χ [ 0..high ) ֮���α����� int
    int nextInt( int high ) 
    {
        return nextInt( 0, high - 1 );
    }
    // ����һ����Χ�� [ low..high ]֮���α��� int 
    int nextInt( int low, int high )
    {
        uniform_int_distribution<int> distribution( low, high );
        return distribution( generator );
    }
    // ����һ���ڷ�Χ [ 0..1 ) ֮���α����� double 
    double nextDouble( )
    {
        static uniform_real_distribution<double> distribution( 0, 1 );
        return distribution( generator );
    }
private:
    mt19937 generator;
};
 