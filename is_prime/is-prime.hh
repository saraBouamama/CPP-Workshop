#include <cmath>

template <unsigned n>
constexpr bool is_prime()
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    for (unsigned i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
