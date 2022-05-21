#include <fstream>
#include <iostream>

ssize_t word_count(const std::string& filename)
{
    std::ifstream file_in;
    std::string cursor;
    file_in.open(filename);
    if (!file_in.is_open())
        return -1;
    int count = 0;
    while (file_in >> cursor)
        count++;
    return count;
}
