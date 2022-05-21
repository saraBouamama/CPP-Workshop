#include "int-container.hh"

#include <iostream>
#include <memory>
#include <sys/types.h>

MyIntContainer::MyIntContainer(size_t size)
    : current_size_(0)
    , max_size_(size)
    , elems_(std::make_unique<int[]>(size))
{}

void MyIntContainer::print() const
{
    for (size_t i = 0; i < current_size_ - 1; i++)
        std::cout << elems_[i] << " | ";
    std::cout << elems_[current_size_ - 1] << '\n';
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (current_size_ >= max_size_)
        return false;
    else
    {
        elems_[current_size_] = elem;
        current_size_ = current_size_ + 1;
        return true;
    }
}

std::optional<int> MyIntContainer::pop()
{
    if (current_size_ == 0)
        return {};
    else
    {
        auto to_remove = elems_[current_size_ - 1];
        elems_[current_size_ - 1] = 0;
        current_size_--;
        return to_remove;
    }
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (current_size_ <= position)
        return {};
    else
        return elems_[position];
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    for (size_t j = 0; j <= current_size_ - 1; j++)
    {
        if (elems_[j] == elem)
            return j;
    }
    return {};
}

void MyIntContainer::sort()
{
    std::sort(elems_.get(), elems_.get() + current_size_);
}

bool MyIntContainer::is_sorted() const
{
    return std::is_sorted(elems_.get(), elems_.get() + current_size_);
}
