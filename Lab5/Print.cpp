#include "Operations.h"

Print::Print(std::vector<std::string> &words) : Operation(words)
{
}

void Print::execute()
{
    std::for_each(words.begin(), words.end(), [](const auto &word)
                  { std::cout << word << " "; });
}

std::string Print::name()
{
    return std::string("Print");
}
