/*
 * @Author: lsyy
 * @Date: 2020-02-28 11:37:49
 * @LastEditTime: 2020-02-28 19:42:31
 * @LastEditors: Please set LastEditors
 * @Description: 不相交集合类
 * @FilePath: \DisjSets\Src\main.cpp
 */


#include <iostream>
#include "DisjSets.h"

int main( )
{
    DisjSets ds( 9 );
    ds.unionSetsBySzie( 4, 5 );
    ds.unionSetsBySzie( 6, 7 );
    ds.unionSetsBySzie( 4, 6 );
    ds.unionSetsBySzie( 3, 4 );
    // int pos = ds.find( 7 );
    // pos = ds.find( 6 );
    // pos = ds.find( 5 );
    // pos = ds.find( 4 );

    return 0;
}