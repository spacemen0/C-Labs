#include "Operations.h"

Remove::Remove(std::vector<std::string> &words, const std::string &word) : Operation(words), word(word)
{
}

void Remove::execute()
{
    auto removed = std::remove(words.begin(), words.end(), word);
    words.erase(removed, words.end());
}

std::string Remove::name()
{
    return std::string("Remove");
}