#include "Operations.h"

Table::Table() : Operation()
{
}

Table::Table(const std::vector<std::string> &words) : Operation(words)
{
}

void Table::execute()
{
    std::map<std::string, int> wordMap;
    for (auto word : words)
    {
        if (wordMap.find(word) == wordMap.end())
        {
            wordMap[word] = 1;
        }
        else
        {
            wordMap[word]++;
        }
    }
    for (auto word : wordMap)
    {
        std::cout << word.first << " " << word.second << std::endl;
    }
}

std::string Table::name()
{
    return std::string("Table");
}
