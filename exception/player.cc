#include "player.hh"

#include <exception>
#include <iostream>
using namespace std;

Player::Player(const std::string& name, unsigned int age)

    : name_(name)
    , age_(age)
{
    if (name_.empty())
        throw InvalidArgumentException("Name can't be empty.");

    if (age_ > 150)
        throw InvalidArgumentException("Sorry gramp, too old to play.");
}
