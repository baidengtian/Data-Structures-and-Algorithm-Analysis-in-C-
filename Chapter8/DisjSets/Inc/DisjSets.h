/*
 * @Author: lsyy
 * @Date: 2020-02-28 11:42:01
 * @LastEditTime: 2020-02-28 20:09:24
 * @LastEditors: Please set LastEditors
 * @Description: ���ཻ����
 * @FilePath: \DisjSets\Inc\DisjSets.h
 */
#pragma 

#include <iostream>
#include <vector>

class DisjSets
{

public:
    explicit DisjSets( int numElements ) : s ( numElements - 1 )
    {
        for( int & elem : s )
            elem = -1;
    }
    // ����ϲ��������ཻ����
    void unionSets( int root1, int root2 )
    {
        s[ root2 ] = root1;
    }
    // ������ϲ�
    void unionSetsByHight( int root1, int root2 )
    {
        if( s[ root2 ] < s[ root1 ] )           // ��� root2 �� root1��
            s[ root1 ] = root2;                 // ʹ root2 Ϊ�µĸ�
        else
        {
            if( s[ root1 ] == s[ root2 ] )      // �����ͬ , ����¸߶� 
                --s[ root1 ];
            s[ root2 ] = root1;                 // ʹ root1 Ϊ�¸�
        }
    }
    // ������С�ϲ�
    void unionSetsBySzie( int root1, int root2 )
    {
        if( s[ root2 ] < s[ root1 ] )           // ��� root2 �� root1��
        {
            s[ root2 ] += s[ root1 ];
            s[ root1 ] = root2;                 // ʹ root2 Ϊ�µĸ�
        }           
        else
        {
            s[ root1 ] += s[ root2 ];
            s[ root2 ] = root1;                 // ʹ root1 Ϊ�¸�      
        }
    }
    // Ѱ�� x ���ڼ���
    int find( int x )   const
    {
        if( s[ x ] < 0 )
            return x;
        else
            return find( s[ x ] );
    }
    // Ѱ�� x ���ڼ��� ѹ��·��
    int PathCompressionfind( int x )   
    {
        if( s[ x ] < 0 )
            return x;
        else
            return s[ x ] = find( s[ x ] );
    }
private:
    std::vector<int> s;
};

