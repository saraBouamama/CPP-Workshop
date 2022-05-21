#include "motor-truck.hh"

#include <iostream>
#include <string>

#include "vehicle.hh"
using namespace std;

MotorTruck::MotorTruck(const std::string& model, int fuel, size_t nb_tires)
    : Vehicle(model, fuel)
    , nb_tires_(nb_tires)

{}
void MotorTruck::change_tires() const
{
    cout << "Changing all " << nb_tires_ << " tires of the " << model_ << "\n";
}
