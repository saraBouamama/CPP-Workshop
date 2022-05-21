#include "forward-multiplication.hh"

using lambda_type = std::function<std::function<int(int)>(int)>;
lambda_type create_lambda()
{
    return [=](int first_var) {
        return [=](int second_var) { return (first_var * second_var); };
    };
}
