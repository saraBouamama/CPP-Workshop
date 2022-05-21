#include "unix-path.hh"

#include <string>

#include "path.hh"
std::string UnixPath::to_string() const
{
    std::string filename;
    for (auto& i : path_)
    {
        filename += "/";
        filename += i;
    }
    if (!final_)
        filename += "/";
    return filename;
}