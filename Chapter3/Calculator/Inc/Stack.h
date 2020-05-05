/*
 * @Author: your name
 * @Date: 2020-04-02 17:12:57
 * @LastEditTime: 2020-04-02 17:39:23
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \move\Inc\Stack.h
 */

#pragma
#include <vector>
#include <iostream>
template < typename Object >

class Stack{
public:  
    Stack(  ) { }
    
    ~Stack( ){
        array.clear( );
    }
    
    Stack( const Stack &rhs ) {
        this->array = rhs.array;
    }
    
    Stack( Stack &&rhs ) {
        std::swap( array, rhs.array );
    }
    
    Stack & operator = ( Stack &&rhs ){
        std::swap( array, rhs.array );
        return *this;
    }
    
    Stack & operator = ( const Stack &rhs ){
        array = rhs.array;
        return *this;
    }
    
    // 进栈
    void push( const Object &x ){
        array.push_back( x );
    }
    
    // 出栈
    Object pop( ){
        Object tmp = array.back( );
        array.pop_back( );
        return tmp;
    }
    
    // 返回栈顶元素
    Object top( )   const{
        return array.back( );
    }
    
    // 判断栈是否为空
    bool IsEmpty( ) const{
        return array.empty( );
    }

    // 返回栈的大小
    int size( ) const{
        return array.size( );
    }
    
    // 打印
    void print( )   const{
        for( const auto &x : array )
            std::cout << x << "     ";
        std::cout << std::endl;
    }
    
    // 清空
    void clear( ){
        array.clear( );
    }

private:

    std::vector< Object > array;
};