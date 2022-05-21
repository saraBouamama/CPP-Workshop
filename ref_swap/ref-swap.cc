#include "ref-swap.hh"

#include <iostream>

void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}
