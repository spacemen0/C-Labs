#include "Operations.h"

Table::Table(std::vector<std::string> &words) : Operation(words)
{
}

void Table::execute()
{
    std::map<std::string, int> wordMap;
    std::ranges::for_each(words, [&](std::string &word)
                          { 
            if  (wordMap.find(word) == wordMap.end())
                {
                    wordMap[word] = 1;
                }
                else
                {
                    wordMap[word]++;
                }; });
    std::ranges::for_each(wordMap, [&](std::pair<std::string, int> word)
                          { std::cout << word.first << " " << word.second << std::endl; });
}

std::string Table::name()
{
    return std::string("Table");
}
