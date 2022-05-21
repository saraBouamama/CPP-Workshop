#include "path.hh"

#include <array>
#include <iostream>
#include <string>
#include <vector>
Path& Path::join(const std::string& tail, bool is_file)
{
    if (final_ == false)
    {
        path_.push_back(tail);
        if (is_file)
            final_ = true;
    }
    return *this;
}