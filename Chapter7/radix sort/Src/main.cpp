/*
 * @Author: lsyy
 * @Date: 2020-02-24 10:41:45
 * @LastEditTime: 2020-04-11 16:42:10
 * @LastEditors: Please set LastEditors
 * @Description: 基数排序 ( 卡片排序 )
 * @FilePath: \radix sort\Src\main.cpp
 */
#include <string>
#include <vector>
#include <iostream>


/**
 * @description: 对 string 类对象的数组进行基数排序 
 * @param {type} arry string 类对象的数组 stringLen 所有字符串相同的长度
 * @return: null
 */
void radixSortA( std::vector< std::string > & arry, int stringLen )
{
    const int BUCKETS = 256;
    std::vector< std::vector< std::string > > buckets( BUCKETS );

    // 逐个字母排序 先排单词末尾字母 再排单词首字母
    for( int pos = stringLen - 1; pos >= 0; --pos )
    {
        // 桶形排序
        for( std::string & s : arry )
            buckets[ s[ pos ] ].push_back( s );
        
        int idx = 0;
        // 保留当前趟的序
        for( auto & thisBucket : buckets )
        {
            for( std::string & s : thisBucket )
                arry[ idx++ ] = std::move( s );
            
            thisBucket.clear( );
        }
    }
}
/**
 * @description: 对 string 类对象的数组进行计数排序 
 * @param {type} arr string 类对象的数组 stringLen 所有字符串相同的长度
 * @return: null
 */
void countingRadixSort( std::vector<std::string> & arr, int stringLen )
{
    const int BUCKETS = 256;
    int N = arr.size( );
    std::vector<std::string> buffer( N );

    std::vector<std::string>* in = &arr;
    std::vector<std::string>* out = &buffer;

    for( int pos = stringLen - 1; pos >= 0; --pos )
    {
        std::vector<int> count( BUCKETS + 1 );

        for( int i = 0; i < N; ++i )
            ++count[ ( *in )[ i ][ pos ] + 1 ];

        for( int b = 1; b <= BUCKETS; ++b )
            count[ b ] += count[ b - 1 ];

        for( int i = 0; i < N; ++i )
            ( *out )[ count[ ( *in )[ i ][ pos ] ]++ ] = std::move( (*in)[ i ] );
        // 交换 in 和 out 的角色
        std::swap( in, out ); 
    }

    // 如果是奇数趟 in 是 buffer out 是 arr ; 从而用 move 再将 *in 传给 *out
    if( stringLen % 2 == 1 )
        for( int i = 0; i < arr.size( ); ++i )
            ( *out )[ i ] = std::move( ( *in )[ i ] ); 

}
/**
 * @description: 对 string 类对象的数组进行基数排序 
 * @param {type} arr string 类对象的数组 maxLen 所有字符串的长度均以 maxLen 为界
 * @return: null
 */
void radixSort( std::vector<std::string> & arr, int maxLen )
{
    const int BUCKETS = 256;
     
    std::vector<std::vector<std::string>> wordsByLength( maxLen + 1 );
    std::vector<std::vector<std::string>> buckets( BUCKETS );

    // 按单词长度桶形排序
    for( std::string & s : arr )
        wordsByLength[ s.length( ) ].push_back( s );


    int idx = 0;

    for( auto & wordsList : wordsByLength )
        for( std::string & s : wordsList )
            arr[ idx++ ] = std::move( s );


    // 按照每个单词的字母排序
    int startingIndex = arr.size( );
    for( int pos = maxLen - 1; pos >= 0; --pos )
    {
        // 拥有 pos 位的单词数
        startingIndex -= wordsByLength[ pos + 1 ].size( );

        // 对拥有 pos 位的单词进行桶排序
        for( int i = startingIndex; i < arr.size( ); ++i )
            buckets[ arr[ i ][pos] ].push_back( std::move( arr[ i ] ) );

        idx = startingIndex;

        // 保留当前趟的顺序
        for( auto & thisBucket : buckets )
        {
            for( std::string & s : thisBucket )
                arr[ idx++ ] = std::move( s );

            thisBucket.clear( );
        }
    }

}

int main( )
{
    // std::vector<std::string> vs;
    // vs.push_back( "acda" );
    // vs.push_back( "adca" );
    // vs.push_back( "bcda" );
    // vs.push_back( "ccda" );
    // vs.push_back( "cdca" );
    // vs.push_back( "dcda" );
    // vs.push_back( "dcea" );
    // radixSortA( vs, 4 );
    // countingRadixSort( vs, 4 );


    std::vector<std::string> vs2;
    vs2.push_back( "aca" );
    vs2.push_back( "cda" );
    vs2.push_back( "da" );
    vs2.push_back( "a" );
    vs2.push_back( "acda" );
    vs2.push_back( "acida" );
    vs2.push_back( "acdpa" );
    vs2.push_back( "gacda" );
    vs2.push_back( "ggacda" );
    radixSort( vs2, 6 );

    return 0;
}