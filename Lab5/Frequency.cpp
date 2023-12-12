#include "Operations.h"

Frequency::Frequency(std::vector<std::string> &words, int maxLen) : Operation(words), maxLen(maxLen)
{
}

void Frequency::execute()
{
    std::map<std::string, int> frequencyMap;

    std::ranges::for_each(words, [&](const auto &word)
                          { frequencyMap[word] = std::count(words.begin(), words.end(), word); });

    std::vector<std::pair<std::string, int>> frequencyVector(frequencyMap.begin(), frequencyMap.end());
    std::sort(frequencyVector.begin(), frequencyVector.end(),
              [](const auto &a, const auto &b)
              { return a.second > b.second; });

    std::cout << std::right;
    std::ranges::for_each(frequencyVector, [&](const auto &pair)
                          { std::cout << std::setw(maxLen) << pair.first << " " << pair.second << std::endl; });
}

std::string Frequency::name()
{
    return std::string("Frequency");
}
