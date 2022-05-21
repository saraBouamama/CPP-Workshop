#pragma once

#include <string>

class Soldier
{
public:
    Soldier(int Health_ = 15, unsigned Damage_ = 3,
            std::string scream_ = "No pity for losers!");

    void attack(Soldier& s);
    void print_state() const;
    void scream() const;

protected:
    int Health_;
    unsigned Damage_;
    std::string scream_;
};