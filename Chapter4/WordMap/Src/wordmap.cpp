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
 * @description: 打印只有一个字母不同的单词
 * @param {type} adjacentWords 存放单词map容器 minWords 打印拥有彼此互异单词的数量超过minWords的单词
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
 * @description: 判断两个单词是否只有一个字母不同
 * @param {type} word1单词1 word2单词2 
 * @return: 两个单词只有一个字母不同返回ture 否则false
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
 * @description: 将字典中单词之间只有一个字母不同的单词存放到map中
 * @param {type} words 存放字典中所有单词的容器
 * @return: 分类好的map容器
 */
std::map<std::string, std::vector<std::string>> computeAdjacentWords( const std::vector<std::string> & words )
{
    std::map<std::string, std::vector<std::string>> adjWords;
    std::map<int, std::vector<std::string>> wordsByLength;
    
    // 按单词长度对单词进行存储
    for( auto & thisWord : words )
        wordsByLength[ thisWord.length() ].push_back( thisWord );
    
    // 对每组进行分类
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