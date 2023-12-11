#include "Operations.h"

Print::Print() : Operation()
{
}

Print::Print(const std::vector<std::string> &words) : Operation(words)
{
}

void Print::execute()
{
    for (auto word : words)
    {
        std::cout << word << std::endl;
    }
}

std::string Print::name()
{
    return std::string("Print");
}
