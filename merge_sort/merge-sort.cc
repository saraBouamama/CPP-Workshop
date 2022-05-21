#include "merge-sort.hh"

#include <algorithm>
#include <vector>

void merge_sort(iterator_type begin, iterator_type end)
{
    int size = distance(begin, end);
    if (size <= 1)
        return;
    iterator_type middle = begin + (end - begin) / 2;
    merge_sort(begin, middle);
    merge_sort(middle, end);
    inplace_merge(begin, middle, end);
    return;
}
