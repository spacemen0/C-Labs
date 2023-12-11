#include "Operations.h"

Substitute::Substitute(std::vector<std::string> &words, const std::string &oldWord, const std::string &newWord) : Operation(words), oldWord(oldWord), newWord(newWord)
{
}

void Substitute::execute()
{
    std::ranges::for_each(words, [&](std::string &word)
                          {
        if (word == oldWord) {
            word = newWord;
        } });
}

std::string Substitute::name()
{
    return std::string("Substitute");
}