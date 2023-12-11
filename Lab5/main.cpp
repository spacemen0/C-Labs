#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
#include "Operation.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc <= 3)
    {
        cerr << "Error: Insufficient command-line arguments.\n"
             << "Usage: " << argv[0]
             << " <filename> <operations> [input]" << endl;
        return 1;
    }

    string filename = argv[1];
    vector<pair<string, string>> arguments;
    for (int i = 2; i < argc; i += 1)
    {
        string arg = argv[i];
        // TO-DO: check if arg is valid
        if (arg.find('=') == string::npos)
        {
            string operation = arg.substr(2);
            arguments.push_back(make_pair(operation, ""));
        }
        else
        {
            string operation = arg.substr(2, arg.find('=') - 2);
            string parameter = arg.substr(arg.find('=') + 1);
            arguments.push_back(make_pair(operation, parameter));
        }
    }

    // for (auto &argument : arguments)
    // {
    //     cout << argument.first << " " << argument.second << endl;
    // }

    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Cannot open file '" << filename << "'." << endl;
        return 1;
    }

    vector<string> words;
    string word;
    while (file >> word)
    {
        words.push_back(word);
    }
    file.close();

    // for (auto &word : words)
    // {
    //     cout << word << endl;
    // }
}