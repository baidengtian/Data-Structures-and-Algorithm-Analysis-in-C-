/*
 * @Author: your name
 * @Date: 2020-03-14 17:55:09
 * @LastEditTime: 2020-03-14 19:53:58
 * @LastEditors: Please set LastEditors
 * @Description: 产生随机数类
 * @FilePath: \random\Inc\random.h
 */

#pragma 

static const int A = 48271;
static const int M = 2147483647;
static const int Q = M / A;
static const int R = M % A;

class random
{
public:
    explicit random( int initialValue = 1 )
    {
        if( initialValue < 0 )
            initialValue += M;
        state = initialValue;
        if( state == 0 )
            state = 1;
    }
    int randomInt( )
    {
        int tmpState = A * ( state % Q ) - R * ( state / Q );
        if( tmpState >= 0 )
            state = tmpState;
        else
            state = tmpState +  M;
        
        return state;
    }
    double random0_1( )
    {
        return static_cast<double>( randomInt( ) ) / M;
    }
    int randomInt( int low, int high )
    {
        double partitionSize = static_cast<double>( M ) / ( high - low + 1 );

        return static_cast<int>( randomInt( ) / partitionSize ) + low;
    }
private:
    int state;
};

 