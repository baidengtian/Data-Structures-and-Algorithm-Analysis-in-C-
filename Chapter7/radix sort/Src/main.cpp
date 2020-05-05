/*
 * @Author: lsyy
 * @Date: 2020-02-24 10:41:45
 * @LastEditTime: 2020-04-11 16:42:10
 * @LastEditors: Please set LastEditors
 * @Description: �������� ( ��Ƭ���� )
 * @FilePath: \radix sort\Src\main.cpp
 */
#include <string>
#include <vector>
#include <iostream>


/**
 * @description: �� string ������������л������� 
 * @param {type} arry string ���������� stringLen �����ַ�����ͬ�ĳ���
 * @return: null
 */
void radixSortA( std::vector< std::string > & arry, int stringLen )
{
    const int BUCKETS = 256;
    std::vector< std::vector< std::string > > buckets( BUCKETS );

    // �����ĸ���� ���ŵ���ĩβ��ĸ ���ŵ�������ĸ
    for( int pos = stringLen - 1; pos >= 0; --pos )
    {
        // Ͱ������
        for( std::string & s : arry )
            buckets[ s[ pos ] ].push_back( s );
        
        int idx = 0;
        // ������ǰ�˵���
        for( auto & thisBucket : buckets )
        {
            for( std::string & s : thisBucket )
                arry[ idx++ ] = std::move( s );
            
            thisBucket.clear( );
        }
    }
}
/**
 * @description: �� string ������������м������� 
 * @param {type} arr string ���������� stringLen �����ַ�����ͬ�ĳ���
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
        // ���� in �� out �Ľ�ɫ
        std::swap( in, out ); 
    }

    // ����������� in �� buffer out �� arr ; �Ӷ��� move �ٽ� *in ���� *out
    if( stringLen % 2 == 1 )
        for( int i = 0; i < arr.size( ); ++i )
            ( *out )[ i ] = std::move( ( *in )[ i ] ); 

}
/**
 * @description: �� string ������������л������� 
 * @param {type} arr string ���������� maxLen �����ַ����ĳ��Ⱦ��� maxLen Ϊ��
 * @return: null
 */
void radixSort( std::vector<std::string> & arr, int maxLen )
{
    const int BUCKETS = 256;
     
    std::vector<std::vector<std::string>> wordsByLength( maxLen + 1 );
    std::vector<std::vector<std::string>> buckets( BUCKETS );

    // �����ʳ���Ͱ������
    for( std::string & s : arr )
        wordsByLength[ s.length( ) ].push_back( s );


    int idx = 0;

    for( auto & wordsList : wordsByLength )
        for( std::string & s : wordsList )
            arr[ idx++ ] = std::move( s );


    // ����ÿ�����ʵ���ĸ����
    int startingIndex = arr.size( );
    for( int pos = maxLen - 1; pos >= 0; --pos )
    {
        // ӵ�� pos λ�ĵ�����
        startingIndex -= wordsByLength[ pos + 1 ].size( );

        // ��ӵ�� pos λ�ĵ��ʽ���Ͱ����
        for( int i = startingIndex; i < arr.size( ); ++i )
            buckets[ arr[ i ][pos] ].push_back( std::move( arr[ i ] ) );

        idx = startingIndex;

        // ������ǰ�˵�˳��
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