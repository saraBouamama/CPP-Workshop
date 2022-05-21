#include "soldier.hh"

#include <iostream>

Soldier::Soldier(int health, unsigned Damage, std::string scream)

    : Health_(health)
    , Damage_(Damage)
    , scream_(scream)
{}

void Soldier::attack(Soldier& s)
{
    s.Health_ -= Damage_;
}

void Soldier::print_state() const
{
    std::cout << "I have " << Health_ << " health points." << '\n';
}

void Soldier::scream() const
{
    std::cout << scream_ << '\n';
}
