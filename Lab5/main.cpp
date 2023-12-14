#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
#include "Operations.h"
using namespace std;

void processArgument(const pair<string, string> &argument, vector<Operation *> &operations, vector<string> &words, size_t maxLen)
{
    if (argument.first == "print")
    {
        operations.push_back(new Print(words));
    }
    else if (argument.first == "frequency")
    {
        operations.push_back(new Frequency(words, maxLen));
    }
    else if (argument.first == "table")
    {
        operations.push_back(new Table(words, maxLen));
    }
    else if (argument.first == "substitute")
    {
        operations.push_back(new Substitute(words, argument.second.substr(0, argument.second.find('+')), argument.second.substr(argument.second.find('+') + 1)));
    }
    else if (argument.first == "remove")
    {
        operations.push_back(new Remove(words, argument.second));
    }
    else
    {
        throw invalid_argument("Unknown operation '" + argument.first + "'.");
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cerr << "Error: Insufficient command-line arguments.\n"
             << "Usage: " << argv[0]
             << " <filename> <operations> [input]" << endl;
        return 1;
    }

    string filename = argv[1];
    // Rewrite using ranges::for_each
    vector<pair<string, string>> arguments;
    for (int i = 2; i < argc; i += 1)
    {
        string arg = argv[i];
        if (arg.find('=') == string::npos)
        {
            string flag;
            try
            {
                flag = arg.substr(2);
            }
            catch (const out_of_range &e)
            {
                cerr << "Error: Invalid argument '" << arg << "'." << endl;
            }

            arguments.push_back(make_pair(flag, ""));
        }
        else
        {
            string flag, parameter;
            try
            {
                flag = arg.substr(2, arg.find('=') - 2);
                parameter = arg.substr(arg.find('=') + 1);
            }
            catch (const out_of_range &e)
            {
                cerr << "Error: Invalid argument '" << arg << "'." << endl;
            }
            arguments.push_back(make_pair(flag, parameter));
        }
    }

    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Cannot open file '" << filename << "'." << endl;
        return 1;
    }

    vector<string> words;
    copy(istream_iterator<string>(file), istream_iterator<string>(), back_inserter(words));
    size_t maxLen = 0;
    ranges::for_each(words, [&](auto &word)
                     { maxLen = maxLen < word.length() ? word.length() : maxLen; });
    file.close();
    vector<Operation *> operations;
    ranges::for_each(arguments, [&](const auto &argument)
                     { try
                          {
                              processArgument(argument, operations, words, maxLen);
                          }
                          catch(const invalid_argument& e)
                          {
                            cerr << e.what() << '\n';
                          } });

    ranges::for_each(operations, [](auto &operation)
                     { operation->execute(); });  
}