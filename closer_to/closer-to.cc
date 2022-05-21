#include "closer-to.hh"

#include <iostream>

CloserTo::CloserTo(int i)
    : i_(i)
{}

bool CloserTo::operator()(const int& a, const int& b) const
{
    int distance_a = a - i_;
    int distance_b = b - i_;

    if (distance_a < 0)
    {
        distance_a *= -1;
    }

    if (distance_b < 0)
    {
        distance_b *= -1;
    }

    if (distance_a < distance_b)
    {
        return true;
    }

    if (distance_a == distance_b)
    {
        return a < b;
    }
    return false;
}
