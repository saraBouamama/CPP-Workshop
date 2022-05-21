#include "parse-csv.hh"

#include <fstream>
#include <iostream>

std::vector<std::vector<std::string>> parse_csv(const std::string& file_name)
{
    std::ifstream file;
    file.open(file_name);
    if (!file.is_open())
        throw std::ios_base::failure("Error opening file");

    std::string ster_original;
    std::vector<std::vector<std::string>> array;

    int ster_imitation = 0;
    int number = 0;

    while (std::getline(file, ster_original))
    {
        int zeb_li_kidouz = 0;
        ster_imitation++;
        std::vector<std::string> vector_dial_ster;
        for (;;)
        {
            if (ster_imitation == 1)
                number++;
            zeb_li_kidouz++;
            auto ster_finder = ster_original.find(",");
            vector_dial_ster.push_back(ster_original.substr(0, ster_finder));
            ster_original.erase(0, ster_finder + 1);
            if (ster_finder == std::string::npos)
                break;
        }

        if (zeb_li_kidouz != number)
        {
            std::string errline = std::to_string(ster_imitation);
            std::string err =
                "Non consistent number of columns at line " + errline;
            throw std::ios_base::failure(err);
        }
        array.push_back(vector_dial_ster);
    }
    file.close();

    return array;
}
