#include "Operations.h"

Table::Table(std::vector<std::string> &words, std::size_t maxLen) : Operation(words), maxLen(maxLen)
{
}

void Table::execute()
{
    std::map<std::string, int> wordMap;
    std::for_each(words.begin(), words.end(), [&](const auto &word)
                  { wordMap[word] = std::count(words.begin(), words.end(), word); });
    std::cout << std::left;
    std::for_each(wordMap.begin(), wordMap.end(), [&](const auto &word)
                  { std::cout << std::setw(maxLen) << word.first << " " << word.second << std::endl; });
}

std::string Table::name()
{
    return std::string("Table");
}
