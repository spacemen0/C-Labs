#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <map>
#include <iostream>
class Operation
{
public:
    Operation(std::vector<std::string> &words);
    virtual void execute() = 0;
    ~Operation() = default;
    virtual std::string name() = 0;

protected:
    std::vector<std::string> &words;
};

class Print : public Operation
{
public:
    Print(std::vector<std::string> &words);
    void execute() override;
    std::string name() override;
};

class Frequency : public Operation
{
public:
    Frequency(std::vector<std::string> &words);
    void execute() override;
    std::string name() override;
};

class Table : public Operation
{
public:
    Table(std::vector<std::string> &words);
    void execute() override;
    std::string name() override;
};

class Substitute : public Operation
{
public:
    Substitute(std::vector<std::string> &words, const std::string &oldWord, const std::string &newWord);
    void execute() override;
    std::string name() override;

private:
    std::string oldWord;
    std::string newWord;
};

class Remove : public Operation
{
public:
    Remove(std::vector<std::string> &words, const std::string &word);
    void execute() override;
    std::string name() override;

private:
    std::string word;
};

#endif // OPERATIONS_H