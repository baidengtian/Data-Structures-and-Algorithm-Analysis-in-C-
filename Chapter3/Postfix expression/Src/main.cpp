/*
 * @Author: your name
 * @Date: 2020-04-02 19:29:10
 * @LastEditTime: 2020-04-03 10:44:01
 * @LastEditors: Please set LastEditors
 * @Description: Stack ��׺���ʽ
 * @FilePath: \Stack\Src\main.cpp
 */


#include <iostream>
#include "Stack.h"
#include <vector>
#include <string>
#include <map>
/**
 * @description: ƽ����ţ���������Ƿ��Ӧ 
 * @param {type} str ������ַ���
 * @return: ƽ�� true ���� false
 */
bool BalancingSymbols( const std::string &str ){
    Stack<char> s;
    for( auto c : str ){
        if( c == '(' || c == '[' || c == '{' ){
            s.push( c );                        // ��ջ
        }
        else if( c == ')' || c == ']' || c == '}' ){
            if( s.IsEmpty( ) ){
                std::cout << " unbalancing symbols1!!! " << std::endl;
                return false;
            }
            char tmp = s.pop( );                // ��ջ
            if( ( c == '(' && tmp != ')' )
            || ( c == '[' && tmp != ']' ) 
            || ( c == '{' && tmp != '}' )){
                std::cout << " unbalancing symbols2!!! " << std::endl;
                return false;
            }
        }
    }
    if( !s.IsEmpty( ) ){
        std::cout << " unbalancing symbols3!!! " << std::endl;
        return false;
    }
    return true;
}

inline bool IsSymbol( char c ){
    return ( c == '+' || c == '-' || c == '*' 
            || c == '/' ||c == '(' || c == ')' );
}

/**
 * @description: ��׺��� --> ��׺���ʽ 
 * @param {type} str ��׺���ʽ
 * @return: ��׺���ʽ
 */
std::string InfixToPostfix( const std::string &str ){
    std::map<char, char> priority;          // ������������ȼ�
    priority['-'] = 1;
    priority['+'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['('] = 5;
    Stack< char > symbol;
    std::string retStr;
    for( auto c : str ){

        if( !IsSymbol( c ) )                // ��ǰ�ַ����� + - * / ( )
            retStr += c;
        else {                              // ��ǰ�ַ��� + - * / ( )
            if( symbol.IsEmpty( ) )
                symbol.push( c );
            else{
                // ( ��ջ���ȼ���� ��ջ���ȼ����
                priority['('] = ( c == '(' ? 5 : 0 );
         
                if( c == ')' ){             // ��ǰ�ַ��� ) ����ջ��Ԫ�� ֱ����Ӧ ( ����ʱ
                    
                    while ( symbol.top( ) != '(' )
                        retStr += symbol.pop( ); 
                    symbol.pop( );          // ���� (
                
                }else{

                    while( priority[ symbol.top( ) ] >= priority[ c ] )     // ����Ԫ��ֱ���бȵ�ǰԪ�ظ��͵�Ԫ��
                        retStr += symbol.pop( );
                    symbol.push( c );                                       // ��ջ
                
                }
            }

        }
    }
    while( !symbol.IsEmpty( ) )             // ����ջ��ʣ��Ԫ��
        retStr += symbol.pop( );
    return retStr;
}
inline int Operation( int num1, char c, int num2 ){
    int result = 0;
    switch ( c ) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            break;
    }
    return result;
}

int PosfixOperation( std::string &str ){
    Stack< int > numstack;
    for( auto &c : str ){
        if( !IsSymbol( c ) )
            numstack.push( c - '0' );
        else{
            int num1 = numstack.pop( );
            int num2 = numstack.pop( );
            numstack.push( Operation( num2, c, num1 ) );
        }
    }
    return numstack.pop( );
}

int main( ){


    // const std::string s{ "abd{d{[dd[dd(deekkkkkkk)]lll}" };
    // bool flag = BalancingSymbols( s );
    // const std::string infix{ "a+b*c+(d*e+f)*g" };
    // std::string postfix = InfixToPostfix( infix );

    const std::string str( "1+1*2+(8*9-1)*6" );
    std::string postfix = InfixToPostfix( str );
    int result = PosfixOperation( postfix );
    // std::vector<int> v;
    // v.push_back( 1 );
    // v.push_back( 2 );
    // v.push_back( 3 );

    // v.pop_back( );
    // Stack<int> s;
    // s.push( 1 );
    // s.push( 2 );
    // s.push( 3 );
    // s.print( );
    // s.pop( );
    // int num = s.top( );
    // Stack<int> s1( s );
    // Stack<int> s2;
    // s2 = s1;
    // s2.clear( );
    return 0;
}