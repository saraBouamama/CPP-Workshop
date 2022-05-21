#include "find-optional.hh"

#include <iostream>
#include <optional>
#include <vector>

std::optional<std::size_t> find_optional(const std::vector<int>& vect,
                                         int value)
{
    auto count = 0;
    for (auto i : vect)
    {
        if (i == value)
            return count;
        count++;
    }
    return {};
}
