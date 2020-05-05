/*
 * @Author: your name
 * @Date: 2020-02-10 10:13:13
 * @LastEditTime : 2020-02-10 11:08:01
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \WordMap\Inc\wordmap.h
 */
#ifndef __WORDMAP_H
#define __WORDMAP_H

#include <iostream>
#include <map>
#include <vector>



void printHighChangeables( const std::map < std::string, std::vector<std::string> >& adjacentWords, int minWords);
bool oneCharOff( const std::string & word1, const std::string & word2);
std::map<std::string, std::vector<std::string>> computeAdjacentWords( const std::vector<std::string> & words );

#endif
