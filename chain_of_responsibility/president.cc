#include "president.hh"

#include <iostream>

void President::handle_request(int level)
{
    if (level <= 9)
    {
        std::cout << "President handles" << std::endl;
    }
    else
        forward_request(level);
}