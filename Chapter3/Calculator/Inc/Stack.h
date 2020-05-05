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
    
    // ��ջ
    void push( const Object &x ){
        array.push_back( x );
    }
    
    // ��ջ
    Object pop( ){
        Object tmp = array.back( );
        array.pop_back( );
        return tmp;
    }
    
    // ����ջ��Ԫ��
    Object top( )   const{
        return array.back( );
    }
    
    // �ж�ջ�Ƿ�Ϊ��
    bool IsEmpty( ) const{
        return array.empty( );
    }

    // ����ջ�Ĵ�С
    int size( ) const{
        return array.size( );
    }
    
    // ��ӡ
    void print( )   const{
        for( const auto &x : array )
            std::cout << x << "     ";
        std::cout << std::endl;
    }
    
    // ���
    void clear( ){
        array.clear( );
    }

private:

    std::vector< Object > array;
};