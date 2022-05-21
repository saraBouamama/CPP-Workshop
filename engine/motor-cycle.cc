#include "motor-cycle.hh"

#include <iostream>
#include <string>

#include "vehicle.hh"

using namespace std;

MotorCycle::MotorCycle(const std::string& model)
    : Vehicle(model, 20)
{}

void MotorCycle::change_tires() const
{
    cout << "Changing front and back wheels of the " << model_ << "\n";
}
