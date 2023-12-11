#include "Operations.h"

Remove::Remove() : Operation()
{
}

Remove::Remove(const std::vector<std::string> &words, const std::string &word) : Operation(words), word(word)
{
}

void Remove::execute()
{
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == word)
        {
            words.erase(words.begin() + i);
            i--;
        }
    }
}

std::string Remove::name()
{
    return std::string("Remove");
}