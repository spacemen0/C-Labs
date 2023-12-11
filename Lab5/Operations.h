#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
class Operation
{
public:
    Operation();
    Operation(const std::vector<std::string> &words);
    virtual void execute() = 0;
    ~Operation() = default;
    virtual std::string name() = 0;

protected:
    std::vector<std::string> words;
};

class Print : public Operation
{
public:
    Print();
    Print(const std::vector<std::string> &words);
    void execute() override;
    std::string name() override;
};

class Frequency : public Operation
{
public:
    Frequency();
    Frequency(const std::vector<std::string> &words);
    void execute() override;
    std::string name() override;
};

class Table : public Operation
{
public:
    Table();
    Table(const std::vector<std::string> &words);
    void execute() override;
    std::string name() override;
};

class Substitute : public Operation
{
public:
    Substitute();
    Substitute(const std::vector<std::string> &words, const std::string &oldWord, const std::string &newWord);
    void execute() override;
    std::string name() override;

private:
    std::string oldWord;
    std::string newWord;
};

class Remove : public Operation
{
public:
    Remove();
    Remove(const std::vector<std::string> &words, const std::string &word);
    void execute() override;
    std::string name() override;

private:
    std::string word;
};

#endif // OPERATIONS_H