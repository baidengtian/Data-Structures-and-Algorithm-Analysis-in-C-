/*
 * @Author: your name
 * @Date: 2020-02-11 16:31:25
 * @LastEditTime: 2020-02-15 20:22:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CuckooHash Table\Src\main.cpp
 */


#include <iostream>
#include <string>
#include "CuckooHashTab.h"
#include "StringHashFamily.h"
#include <vector>

using namespace std;


int main( )
{

    const int NUMS = 2000000;
    const int GAP  =   37;
    const int ATTEMPTS = 1;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( int att = 0; att < ATTEMPTS; ++att )
    { 
        cout << "ATTEMPT: " << att << endl;
        
        CuckooHashTable<string,StringHashFamily<3>> h1;
        CuckooHashTable<string,StringHashFamily<3>> h2;
        
        for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        {
            if( !h1.insert( to_string( i ) ) )
            {
                cout << "OOPS insert fails!! " << i << endl;
            }
            
        }

        for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
            if( h1.insert( to_string( i ) ) )
                cout << "INSERT OOPS!!! " << i << endl;
        
        h2 = h1;
        
        for( i = 1; i < NUMS; i += 2 )
            h2.remove( to_string( i ) );
        
        for( i = 2; i < NUMS; i += 2 )
            if( !h2.contains( to_string( i ) ) )
                cout << "Contains fails " << i << endl;
        
        for( i = 1; i < NUMS; i += 2 )
        {
            if( h2.contains( to_string( i ) ) )
                cout << "CONTAINS OOPS!!! " <<  i << endl;
        }
        
        cout << "END OF ATTEMPT" << endl;
        
        if( h2.capacity( ) > NUMS * 4 )
            cout << "LARGE CAPACITY " << h2.capacity( ) << endl;
        
    }

    return 0;
}


// int main()
// {    

//     CuckooHashTable<std::string,StringHashFamily<2>> ht(5);
//     ht.insert("bai");
//     ht.insert("deng");
//     ht.insert("tian");
//     ht.insert("zyy");
//     ht.insert("yhy");
//     ht.insert("wzx");
//     bool falg = ht.contains("bai");
//     ht.print();
    
//     ht.remove("bai");
//     std::cout << std::endl << std::endl;
//     ht.print();

//     ht.makeEmpty();
//     std::cout << std::endl << std::endl;
//     ht.print();
//     return 0;
// }