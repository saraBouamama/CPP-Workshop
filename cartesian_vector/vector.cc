#include "vector.hh"

std::ostream& operator<<(std::ostream& os, const Vector& vect)
{
    return os << '{' << vect.x << ',' << vect.y << '}';
}

Vector& Vector::operator+=(const Vector& rhs)
{
    *this = *this + rhs;
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    *this = *this - rhs;
    return *this;
}

Vector& Vector::operator*=(int scalar)
{
    *this = *this * scalar;
    return *this;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    auto res = Vector(lhs.x + rhs.x, lhs.y + rhs.y);
    return res;
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    auto res = Vector(lhs.x - rhs.x, lhs.y - rhs.y);
    return res;
}

Vector operator*(const Vector& lhs, int scalar)
{
    auto res = Vector(lhs.x * scalar, lhs.y * scalar);
    return res;
}

Vector operator*(int scalar, const Vector& rhs)
{
    auto res = Vector(scalar * rhs.x, scalar * rhs.y);
    return res;
}

int operator*(const Vector& lhs, const Vector& rhs)
{
    auto res = lhs.x * rhs.x + lhs.y * rhs.y;
    return res;
}
