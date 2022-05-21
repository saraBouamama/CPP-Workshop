#include "regiment.hh"

void Regiment::clean_reg()
{
    regiment_.clear();
}

void Regiment::join_by(Regiment& r)
{
    for (auto cursor : r.regiment_)
    {
        regiment_.push_back(cursor);
    }
    r.clean_reg();
}

size_t Regiment::count() const
{
    return regiment_.size();
}

void Regiment::add_soldier(Soldier* s)
{
    regiment_.push_back(s);
}

void Regiment::print_state() const
{
    for (auto cursor : regiment_)
    {
        cursor->print_state();
    }
}

void Regiment::scream() const
{
    for (auto cursor : regiment_)
    {
        cursor->scream();
    }
}