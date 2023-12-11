#include <string>
#include <vector>
#include <utility>

class Argument
{
public:
    Argument();
    Argument(const std::string &operation, const std::string &parameter);

private:
    std::string operation;
    std::string parameter;
};