/*
 * @Author: your name
 * @Date: 2020-02-15 16:08:15
 * @LastEditTime: 2020-04-08 09:57:58
 * @LastEditors: Please set LastEditors
 * @Description: hash函数簇
 * @FilePath: \CuckooHash Table\Inc\StringHashFamily.h
 */
#ifndef __STRINGHASHFAMILY_H
#define __STRINGHASHFAMILY_H


#include <iostream>
#include <vector>
#include <string>
#include "UniformRandom.h"

template < int count >
class StringHashFamily
{

public:
    StringHashFamily( ) : MULTIPLIERS( count )
    {
        // 生成一组哈希值
        generateNewFunctions();
    }
    // 返回哈希函数的个数
    int getNumberOfFunctions( ) const
    {
        return count;
    }
    // 产生一组新的哈希函数
    void generateNewFunctions( )
    {
        for( auto & mult : MULTIPLIERS )
            mult = r.nextInt( );
    }
    // 生产哈希值
    size_t hash( const std::string & x, int which ) const
    {
        const int multiplier = MULTIPLIERS[ which ];
        size_t hashVal = 0;
        
        for( auto ch : x )
            hashVal = multiplier * hashVal + ch;
        
        return hashVal;
    } 
private:
    // 存放产生哈希值的一组随机数
    std::vector<int> MULTIPLIERS;
    // 生成随机数的对象
    UniformRandom r;
};








#endif