#include "Operations.h"

Print::Print(std::vector<std::string> &words) : Operation(words)
{
}

void Print::execute()
{
    std::ranges::for_each(words, [](const auto &word)
                          { std::cout << word << " "; });
}

std::string Print::name()
{
    return std::string("Print");
}
