/*
 * @Author: your name
 * @Date: 2020-04-01 15:57:47
 * @LastEditTime: 2020-04-01 16:50:49
 * @LastEditors: Please set LastEditors
 * @Description: ����������������
 * @FilePath: \max seq\Src\main.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
inline int max3( int x1, int x2, int x3 ){
    return std::max( x1, std::max( x2, x3 ) );
}

/**
 * @description: ���β������������������� NlogN
 * @param {type} a ���� left ��߽� right �ұ߽�
 * @return: ���������֮��
 */
int maxSumRec( const std::vector<int> &a, int left, int right ){
    if( left == right )
        if( a[ left ] > 0 )
            return a[ left ];
        else
            return 0;
    // ����
    int center = ( left + right ) / 2;                  // ��
    int maxLeft = maxSumRec( a, left, center );
    int maxRight = maxSumRec( a, center + 1, right );

    // �м�
    int maxLeftBorderSum = 0, LeftBorderSum = 0;   
    // ���м䵽���     
    for( int i = center; i >= left; --i ){
        LeftBorderSum += a[ i ];
        if( LeftBorderSum > maxLeftBorderSum )
            maxLeftBorderSum = LeftBorderSum;
    }
    int maxRightBorderSum = 0, RightBorderSum = 0;
    // ���м䵽�ұ�  
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
 * @description: ���β������������������� N
 * @param {type} a ���� 
 * @return: ���������֮��
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