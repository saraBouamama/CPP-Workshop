#include "lambdas.hh"

#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

strategy_type cooperator()
{
    return [](iterator_type beg, iterator_type end) {
        (void)beg;
        (void)end;
        return true;
    };
}

strategy_type cheater()
{
    return [](iterator_type beg, iterator_type end) {
        (void)beg;
        (void)end;
        return false;
    };
}

strategy_type copycat()
{
    return [](iterator_type start, iterator_type end) {
        if (start == end || *(end - 1) == 2)
            return true;

        else if (*(end - 1) == -1)
            return false;

        else if (*(end - 1) == 3)
            return true;

        else if (*(end - 1) == 0)
            return false;

        else
        {
            std::cout << "error\n";
            return false;
        }
    };
}

strategy_type grudger()
{
    return [](iterator_type start, iterator_type end) {
        for (auto iter = start; iter != end; iter++)
            if (*iter == -1)
                return false;

        return true;
    };
}

strategy_type detective()
{
    return [](iterator_type start, iterator_type end) {
        if (start == end)
            return true;

        if (start + 1 == end)
            return false;

        if (start + 2 == end)
            return true;

        if (start + 3 == end)
            return true;

        else
        {
            for (auto iter = start; iter != start + 4; iter++)
                if (*iter == -1 || *iter == 0)
                {
                    return copycat()(start, end);
                }

            return false;
        }
    };
}

strategy_type copykitten()
{
    return [](iterator_type start, iterator_type end) {
        if (end > start + 1 && (*(end - 1) == 0 || *(end - 1) == -1)
            && (*(end - 2) == 0 || *(end - 2) == -1))
            return false;

        return true;
    };
}
