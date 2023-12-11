#ifndef OPERATION_H
#define OPERATION_H
#include <string>
#include <vector>
class Operation
{
public:
    Operation();
    Operation(const std::vector<std::string> &parameters, const std::vector<std::string> &words);
    void execute();

private:
    std::vector<std::string> parameters;
    std::vector<std::string> words;
};
#endif // OPERATION_H