#include "vice-president.hh"

#include <iostream>

#include "president.hh"

void VicePresident::handle_request(int level)
{
    if (level <= 6)
        std::cout << "VicePresident handles" << std::endl;
    else
        forward_request(level);
}
