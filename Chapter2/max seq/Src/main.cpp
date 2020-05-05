/*
 * @Author: your name
 * @Date: 2020-04-01 15:57:47
 * @LastEditTime: 2020-04-01 16:50:49
 * @LastEditors: Please set LastEditors
 * @Description: 求解最大子序列问题
 * @FilePath: \max seq\Src\main.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
inline int max3( int x1, int x2, int x3 ){
    return std::max( x1, std::max( x2, x3 ) );
}

/**
 * @description: 分治策略求解最大子序列问题 NlogN
 * @param {type} a 序列 left 左边界 right 右边界
 * @return: 最大子序列之和
 */
int maxSumRec( const std::vector<int> &a, int left, int right ){
    if( left == right )
        if( a[ left ] > 0 )
            return a[ left ];
        else
            return 0;
    // 两边
    int center = ( left + right ) / 2;                  // 分
    int maxLeft = maxSumRec( a, left, center );
    int maxRight = maxSumRec( a, center + 1, right );

    // 中间
    int maxLeftBorderSum = 0, LeftBorderSum = 0;   
    // 从中间到左边     
    for( int i = center; i >= left; --i ){
        LeftBorderSum += a[ i ];
        if( LeftBorderSum > maxLeftBorderSum )
            maxLeftBorderSum = LeftBorderSum;
    }
    int maxRightBorderSum = 0, RightBorderSum = 0;
    // 从中间到右边  
    for( int i = center + 1; i <= right; ++i ){
        RightBorderSum += a[ i ];
        if( RightBorderSum > maxRightBorderSum )
            maxRightBorderSum = RightBorderSum;
    }

    return max3( maxLeft, maxRight, maxRightBorderSum + maxLeftBorderSum );
}


int maxSumRec( std::vector<int> &a ){
    return maxSumRec( a, 0, a.size( ) - 1 );
}

/**
 * @description: 分治策略求解最大子序列问题 N
 * @param {type} a 序列 
 * @return: 最大子序列之和
 */
int maxSumRec2( std::vector<int> &a ){
    int maxSum = 0, Sum = 0;
    for( int x : a ){
        Sum += x;
        if( Sum > maxSum )
            maxSum = Sum;
        else if( Sum < 0 )
            Sum = 0;
    }
    return maxSum;
}

int main( ){

    std::vector<int> sub{ 4, -3, 5, -2, -1, 2, 6, -2 };
    std::cout << maxSumRec( sub ) << std::endl;
    std::cout << maxSumRec2( sub ) << std::endl;
    return 0;
}