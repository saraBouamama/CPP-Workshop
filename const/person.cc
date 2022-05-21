#include "person.hh"

#include <string>

Person::Person(const std::string& name, unsigned int age)
{
    this->name_ = name;
    this->age_ = age;
}

std::string Person::name_get() const
{
    return this->name_;
}

void Person::name_set(const std::string& name)
{
    this->name_ = name;
}

unsigned int Person::age_get() const
{
    return this->age_;
}

void Person::age_set(unsigned int age)
{
    this->age_ = age;
}
