#pragma once

#include "soldier.hh"

class Knight : public Soldier
{
public:
    Knight(int health = 20, int damage = 5,
           std::string scream = "Be quick or be dead!");
};
