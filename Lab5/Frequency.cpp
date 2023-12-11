#include "Operations.h"

Frequency::Frequency() : Operation()
{
}

Frequency::Frequency(const std::vector<std::string> &words) : Operation(words)
{
}

void Frequency::execute()
{
    std::map<std::string, int> frequencyMap;
    for (auto word : words)
    {
        if (frequencyMap.find(word) == frequencyMap.end())
        {
            frequencyMap[word] = 1;
        }
        else
        {
            frequencyMap[word]++;
        }
    }
    for (auto pair : frequencyMap)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

std::string Frequency::name()
{
    return std::string("Frequency");
}
