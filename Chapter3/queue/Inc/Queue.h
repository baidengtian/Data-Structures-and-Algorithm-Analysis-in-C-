/*
 * @Author: your name
 * @Date: 2020-04-03 16:36:49
 * @LastEditTime: 2020-04-04 11:34:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \queue\Inc\Queue.h
 */
#pragma

#include <iostream>

template < typename Object >
class Queue{
public:
    Queue( int resize = 10 ) :  array{ new Object[ resize ] }
    ,front{ &array[1] }, mcapacity{ resize }, back{ array }, size{ 0 } { }
    ~Queue( ){
        delete []array;
        array = nullptr;
        front = nullptr;
        back = nullptr;
    }
    
    // 入队
    void enqueue( Object rhs ){
        if( size == capacity( ) )
            resize( );
        if( back != &array[ capacity( ) - 1 ] )
            *(++back) = rhs;
        else{
            back = &array[0];
            *back = rhs;
        }
        ++size;
    }
    // 扩容
    void resize( ){

        Object *tmp = new Object[ 2 * mcapacity ];
        int i = 0;
        while( !IsEmpty( ) ){
            Object a = dequeue( );
            tmp[ i++ ] = a;
        }

        std::swap( tmp, array );

        size = mcapacity;
        mcapacity *= 2;
          
        front = &array[ 0 ];
        back = &array[ size - 1 ];
        delete [] tmp;
    }
    // 出队
    Object dequeue( ){
        Object tmp = *front;
        *front = Object{ };
        if( front != &array[ capacity( ) - 1 ] )
            ++front;
        else
            front = &array[0];
        --size;
        return tmp;
    }
   
    int capacity( )    const{
        return mcapacity;
    }
   
    int getsize( ) const{
        return size;
    }

    bool IsEmpty( ) const{
        return size == 0;
    }

    void print( )   const{
        Object *tmp = front;
        while( tmp != ( back + 1 ) ){
            if( tmp != &array[ capacity( ) - 1 ] )
                std::cout << *(tmp++) << "  ";
            else{
                tmp = &array[ 0 ];
                std::cout << *tmp << "  ";
            }   
        }
        std::cout << std::endl;      
    }

private:
    Object *array;              // 指向存储数据的数组
    Object *front;              // 指向队头
    Object *back;               // 指向队尾
    int size;                   // 队列大小
    int mcapacity;              // 队列的容量
};
