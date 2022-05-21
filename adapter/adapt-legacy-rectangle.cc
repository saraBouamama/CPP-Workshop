#include "adapt-legacy-rectangle.hh"

#include <iostream>

AdaptLegacyRectangle::AdaptLegacyRectangle(LegacyRectangle& rect)
    : rect_(rect)
{}

AdaptLegacyRectangle::~AdaptLegacyRectangle()
{}

void AdaptLegacyRectangle::print() const
{
    std::cout << "x: " << this->rect_.x1_get() << " y: " << this->rect_.y1_get()
              << '\n';
    if (this->rect_.y2_get() - this->rect_.y1_get() < 0)
        std::cout << "height: "
                  << (this->rect_.y2_get() - this->rect_.y1_get()) * -1 << '\n';
    else
        std::cout << "height: " << this->rect_.y2_get() - this->rect_.y1_get()
                  << '\n';

    if (this->rect_.x2_get() - this->rect_.x1_get() < 0)
        std::cout << "width: "
                  << (this->rect_.x2_get() - this->rect_.x1_get()) * -1 << '\n';
    else
        std::cout << "width: " << this->rect_.x2_get() - this->rect_.x1_get()
                  << '\n';
}
unsigned AdaptLegacyRectangle::area() const
{
    return this->rect_.compute_area();
}
