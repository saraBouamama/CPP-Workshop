#include "windows-path.hh"

#include <string>

#include "path.hh"
#include "unix-path.hh"

WindowsPath::WindowsPath(char drive)
    : drive_(drive)
{}
std::string WindowsPath::to_string() const
{
    std::string file;
    file += drive_;
    file += ":";
    for (auto& position : path_)
    {
        file += "\\";
        file += position;
    }
    if (!final_)
        file += "\\";
    return file;
}

Path& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (!final_)
    {
        if (check_name(tail))
        {
            final_ = is_file;
            path_.push_back(tail); // add at the end
            return *this;
        }
        return *this;
    }
    return *this;
}
bool WindowsPath::check_name(const std::string& name)
{
    if (int(name.find('|')) != -1 || int(name.find(':')) != -1
        || int(name.find('\"')) != -1 || int(name.find('?')) != -1
        || int(name.find("*")) != -1)
        return false;
    return true;
}