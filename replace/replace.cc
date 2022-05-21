#include "replace.hh"

#include <fstream>
#include <iostream>
#include <string>

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ifstream file_in;
    std::ofstream file_out;
    file_in.open(input_filename);
    file_out.open(output_filename);

    if (!file_in)
    {
        std::cerr << "Cannot open input file\n";
        return;
    }

    if (!file_out)
    {
        std::cerr << "Cannot write output file\n";
        return;
    }

    std::string list;
    while (std::getline(file_in, list, '\n'))
    {
        size_t cursor = list.find(src_token);
        while (cursor != std::string::npos)
        {
            list.replace(cursor, src_token.size(), dst_token);
            cursor = list.find(src_token, cursor + dst_token.size());
        }
        file_out << list << std::endl;
    }
    file_in.close();
    file_out.close();
}
