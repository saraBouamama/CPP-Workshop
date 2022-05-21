#pragma once

#include <vector>

#include "assassin.hh"
#include "knight.hh"
#include "soldier.hh"

class Regiment
{
public:
    void clean_reg();
    void join_by(Regiment& r);
    size_t count() const;
    void add_soldier(Soldier* s);
    void print_state() const;
    void scream() const;

private:
    std::vector<Soldier*> regiment_{};
};