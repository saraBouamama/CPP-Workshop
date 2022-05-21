#pragma once

#include "soldier.hh"

class Assassin : public Soldier
{
public:
    Assassin(int health = 10, int damage = 9,
             std::string scream = "Out of the shadows!");
};