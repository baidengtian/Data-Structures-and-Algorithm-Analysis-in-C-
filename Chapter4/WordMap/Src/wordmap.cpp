/*
 * @Author: your name
 * @Date: 2020-02-10 10:12:55
 * @LastEditTime : 2020-02-10 11:07:12
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \WordMap\Src\wordmap.cpp
 */
#include "wordmap.h"


/**
 * @description: ��ӡֻ��һ����ĸ��ͬ�ĵ���
 * @param {type} adjacentWords ��ŵ���map���� minWords ��ӡӵ�б˴˻��쵥�ʵ���������minWords�ĵ���
 * @return: null
 */
void printHighChangeables( const std::map < std::string, std::vector<std::string> >& adjacentWords
                           , int minWords = 15 )
{
    for( auto& entry : adjacentWords )
    {
        const std::vector <std::string>& words = entry.second;
        if (words.size() > minWords)
        {
            std::cout << entry.first << " (" << words.size() <<" ):";
            for(auto & str : entry.second)
                std::cout << "  " << str;
            std::cout << std::endl;
        }        
    }
}
/**
 * @description: �ж����������Ƿ�ֻ��һ����ĸ��ͬ
 * @param {type} word1����1 word2����2 
 * @return: ��������ֻ��һ����ĸ��ͬ����ture ����false
 */
bool oneCharOff( const std::string & word1, const std::string & word2)
{
    if( word1.length() != word2.length() )
        return false;
    int diffs = 0;
    for( int i = 0; i < word1.length(); i++ )
        if( word1[i] != word2[i] )
            diffs++;
    return diffs == 1;   
}
/**
 * @description: ���ֵ��е���֮��ֻ��һ����ĸ��ͬ�ĵ��ʴ�ŵ�map��
 * @param {type} words ����ֵ������е��ʵ�����
 * @return: ����õ�map����
 */
std::map<std::string, std::vector<std::string>> computeAdjacentWords( const std::vector<std::string> & words )
{
    std::map<std::string, std::vector<std::string>> adjWords;
    std::map<int, std::vector<std::string>> wordsByLength;
    
    // �����ʳ��ȶԵ��ʽ��д洢
    for( auto & thisWord : words )
        wordsByLength[ thisWord.length() ].push_back( thisWord );
    
    // ��ÿ����з���
    for( auto & entry : wordsByLength )
    {
        const std::vector<std::string> & groupWords = entry.second;
        for( int i = 0; i < groupWords.size(); ++i )
            for( int j = i + 1; i< groupWords.size(); ++j )
                if( oneCharOff(groupWords[i],groupWords[j]))
                {
                    adjWords[groupWords[i]].push_back(groupWords[j]);
                    adjWords[groupWords[j]].push_back(groupWords[i]);
                }
    }

    return adjWords;
}