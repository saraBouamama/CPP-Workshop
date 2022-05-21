#include <cmath>
#include <iostream>

template <class InputIt, class UnaryFunction>
constexpr UnaryFunction my_foreach(InputIt lewal, InputIt lekhar,
                                   UnaryFunction bach_kanl3bou)
{
    for (; lewal != lekhar; ++lewal)
    {
        bach_kanl3bou(*lewal);
    }
    return bach_kanl3bou;
}
