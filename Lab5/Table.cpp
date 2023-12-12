#include "Operations.h"

Table::Table(std::vector<std::string> &words, int maxLen) : Operation(words), maxLen(maxLen)
{
}

void Table::execute()
{
    std::map<std::string, int> wordMap;
    std::ranges::for_each(words, [&](const auto &word)
                          { wordMap[word] = std::count(words.begin(), words.end(), word); });
    std::cout << std::left;
    std::ranges::for_each(wordMap, [&](const auto &word)
                          { std::cout << std::setw(maxLen) << word.first << " " << word.second << std::endl; });
}

std::string Table::name()
{
    return std::string("Table");
}
