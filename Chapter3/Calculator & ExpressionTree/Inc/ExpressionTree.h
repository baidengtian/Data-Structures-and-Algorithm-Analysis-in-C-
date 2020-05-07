/*
 * @Author: your name
 * @Date: 2020-04-04 12:03:17
 * @LastEditTime: 2020-04-04 12:29:21
 * @LastEditors: Please set LastEditors
 * @Description: 表达树 
 * @FilePath: \Calculator\Inc\ExpressionTree.h
 */
#pragma

#include <iostream>
#include <stack>
#include <string>
template < typename Object >

class ExpressionTree{
private:
    struct Node
    {
        Object element;
        Node *left;
        Node *right;
        Node( Object e = Object{ }, Node *lt = nullptr, Node *rt = nullptr ) 
        : element{ e }, left{ lt }, right{ rt } { } 
    };
    std::stack< Node* > s;
    void print( Node *t ){
        if( t != nullptr ){
            print( t->left );
            std::cout << t->element << "    ";
            print( t->right );
        }
    }
public:
    // 判断是否是运算符
    inline bool IsSymbol( char c )  const{
        return ( c == '+' || c == '-' || c == '*' || c == '/'  );
    }
    
    // 插入操作
    void insert( const Object &x ){
        if( !IsSymbol( x ) )
            s.push( new Node{ x } );
        else{
            Node *rNode = s.top( );
            s.pop( );
            Node *lNode = s.top( );
            s.pop( );
            s.push( new Node{ x, lNode, rNode } ); 
        }
    }

    // 生成最终的表达树
    void CreateExpTree( const std::string &str ){
        for( auto &c : str )
            insert( c );
    }
    // 打印
    void print( )   {
        print( s.top( ) );
    }


};