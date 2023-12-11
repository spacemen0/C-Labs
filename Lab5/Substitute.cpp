#include "Operations.h"

Substitute::Substitute() : Operation()
{
}

Substitute::Substitute(const std::vector<std::string> &words, const std::string &oldWord, const std::string &newWord) : Operation(words), oldWord(oldWord), newWord(newWord)
{
}

void Substitute::execute()
{
    for (auto word : words)
    {
        if (word == oldWord)
        {
            std::cout << newWord << std::endl;
        }
        else
        {
            std::cout << word << std::endl;
        }
    }
}

std::string Substitute::name()
{
    return std::string("Substitute");
}