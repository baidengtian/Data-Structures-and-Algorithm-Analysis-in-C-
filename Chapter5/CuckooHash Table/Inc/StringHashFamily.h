/*
 * @Author: your name
 * @Date: 2020-02-15 16:08:15
 * @LastEditTime: 2020-04-08 09:57:58
 * @LastEditors: Please set LastEditors
 * @Description: hash������
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
        // ����һ���ϣֵ
        generateNewFunctions();
    }
    // ���ع�ϣ�����ĸ���
    int getNumberOfFunctions( ) const
    {
        return count;
    }
    // ����һ���µĹ�ϣ����
    void generateNewFunctions( )
    {
        for( auto & mult : MULTIPLIERS )
            mult = r.nextInt( );
    }
    // ������ϣֵ
    size_t hash( const std::string & x, int which ) const
    {
        const int multiplier = MULTIPLIERS[ which ];
        size_t hashVal = 0;
        
        for( auto ch : x )
            hashVal = multiplier * hashVal + ch;
        
        return hashVal;
    } 
private:
    // ��Ų�����ϣֵ��һ�������
    std::vector<int> MULTIPLIERS;
    // ����������Ķ���
    UniformRandom r;
};








#endif