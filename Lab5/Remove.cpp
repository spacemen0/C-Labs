#include "Operations.h"

Remove::Remove(std::vector<std::string> &words, const std::string &word) : Operation(words), word(word)
{
}

void Remove::execute()
{
    auto removed = std::ranges::remove(words, word);
    words.erase(removed.begin(), removed.end());
}

std::string Remove::name()
{
    return std::string("Remove");
}