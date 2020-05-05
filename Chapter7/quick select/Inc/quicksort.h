/*
 * @Author: your name
 * @Date: 2020-02-26 10:24:02
 * @LastEditTime: 2020-04-10 17:53:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \quick select\Inc\quicksort.h
 */
#ifndef __QUICKSORT_H
#define __QUICKSORT_H


#include <iostream>
#include <functional>
#include <vector>


template < typename Comparable >
void quicksort( std::vector<Comparable> & a );
template < typename Comparable >
const Comparable & median3( std::vector<Comparable> & a, int left, int right );
template < typename Comparable >
void insertionSort(std::vector<Comparable> & a, int left, int right );



#endif


