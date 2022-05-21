#include "director.hh"

#include <iostream>

#include "vice-president.hh"

void Director::handle_request(int level)
{
    if (level <= 3)
        std::cout << "Director handles" << std::endl;
    else
        forward_request(level);
}
