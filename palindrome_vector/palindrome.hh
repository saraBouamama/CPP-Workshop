#pragma once

#include <vector>

template <class T>
bool palindrome(const std::vector<T>& v)
{
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        if (v[i] != v[j])
            return false;
        i++;
        j--;
    }
    return true;
}
