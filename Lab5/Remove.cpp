#include "Operations.h"

Remove::Remove(std::vector<std::string> &words, const std::string &word) : Operation(words), word(word)
{
}

void Remove::execute()
{
    auto pos = std::ranges::remove(words, word);
    words.erase(pos.begin(), pos.end());
}

std::string Remove::name()
{
    return std::string("Remove");
}