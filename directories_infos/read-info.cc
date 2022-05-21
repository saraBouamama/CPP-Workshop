#include "read-info.hh"

DirectoryInfo* read_info(std::ifstream& file_read)
{
    std::string name;
    unsigned int size;
    unsigned int rights;
    std::string owner;
    std::string file;

    if (!(file_read.is_open()))
        return nullptr;

    // Get the line wher im at
    std::getline(file_read, file);

    // check whether or not it's good
    if (correct_way(file) == false)
        return nullptr;

    std::istringstream stream(file);

    if ((!(stream >> name)) or (!(stream >> std::dec >> size))
        or (!(stream >> std::oct >> rights)) or (!(stream >> owner)))
        return nullptr;
    return new DirectoryInfo(name, size, rights, owner);
}

bool correct_way(std::string file)
{
    std::istringstream stream(file);
    std::string pos;
    size_t size = 0;

    while (stream >> pos)
        size++;
    return (size == 4);
}