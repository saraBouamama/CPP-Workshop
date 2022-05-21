#include "engine.hh"

#include <iostream>
#include <string>

using namespace std;

Engine::Engine(int fuel)
{
    this->fuel_ = fuel;
}

bool Engine::start()
{
    if (fuel_ >= 1)
    {
        fuel_--;
        std::cout << "Engine starts with " << fuel_ << " units of fuel"
                  << "\n";
        return true;
    }
    else
        return false;
}
void Engine::use(int consumed)
{
    if (consumed < fuel_)
    {
        fuel_ = fuel_ - consumed;
        cout << "Engine uses " << consumed << " fuel units"
             << "\n";
    }
    else
    {
        cout << "Engine uses " << fuel_ << " fuel units"
             << "\n";
        fuel_ = 0;
    }
}

void Engine::stop() const
{
    cout << "Stop Engine"
         << "\n";
}

void Engine::fill(int fuel)
{
    fuel_ = fuel_ + fuel;
    cout << "Engine now has " << fuel_ << " fuel units"
         << "\n";
}
