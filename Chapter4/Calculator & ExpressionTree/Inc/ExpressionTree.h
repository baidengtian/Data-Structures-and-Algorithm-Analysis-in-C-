/*
 * @Author: your name
 * @Date: 2020-04-04 12:03:17
 * @LastEditTime: 2020-04-04 12:29:21
 * @LastEditors: Please set LastEditors
 * @Description: ����� 
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
    // �ж��Ƿ��������
    inline bool IsSymbol( char c )  const{
        return ( c == '+' || c == '-' || c == '*' || c == '/'  );
    }
    
    // �������
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

    // �������յı����
    void CreateExpTree( const std::string &str ){
        for( auto &c : str )
            insert( c );
    }
    // ��ӡ
    void print( )   {
        print( s.top( ) );
    }


};