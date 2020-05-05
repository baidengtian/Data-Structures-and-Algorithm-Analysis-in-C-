/*
 * @Author: your name
 * @Date: 2019-05-31 22:13:05
 * @LastEditTime : 2020-02-09 16:46:03
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \CPP_DEMO\helloworld.cpp
 */
#include <iostream>
#include <map>
#include <string>
int main()
{

    std::map< std::string, double> salaries;
    salaries[ "pat" ] = 75000.00;
    std::cout << salaries[ "pat" ] << std::endl;
    std::cout << salaries[ "Jan" ] << std::endl;

    std::map<std::string, double> :: const_iterator itr;
    itr = salaries.find( "Chris" );
    if( itr == salaries.end() )
        std::cout << "Not an employee of this company!" << std::endl;
    else
        std::cout << itr->second << std::endl;

    std::cout << "CMake" << std::endl;
    return 0;
}