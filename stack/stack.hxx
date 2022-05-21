#pragma once

#include <iostream>
#include <new>
#include <string>
#include <vector>

#include "stack-creation-failed.hh"
#include "stack-empty.hh"
#include "stack-max-size.hh"

template <class T>

Stack<T>::Stack(size_t max_size)
    : max_size_(max_size)
    , element_()
{
    try
    {
        element_.reserve(max_size);
    }
    catch (const std::length_error& e)
    {
        throw StackCreationFailed("Max stack size is too big.");
    }
    catch (std::bad_alloc& e)
    {
        throw StackCreationFailed("Allocation failed.");
    }
}
template <class T>
Stack<T>& Stack<T>::push(const T& item)
{
    if (this->element_.size() == this->max_size_)
    {
        throw StackMaxSize("Unable to push, stack max size reached.");
    }
    this->element_.push_back(item);
    return *this;
}
template <class T>
T Stack<T>::operator--()
{
    return this->pop();
}
template <class T>
size_t Stack<T>::max_size() const
{
    return this->max_size_;
}
template <class T>
T Stack<T>::operator[](size_t i)
{
    if (i >= element_.size())
    {
        throw std::out_of_range("Out of range.");
    }
    else
    {
        return this->element_[this->element_.size() - i - 1];
    }
}
template <class T>
Stack<T>& Stack<T>::operator+=(const T item)
{
    return push(item);
}
template <class T>
Stack<T>& Stack<T>::operator<<(const T item)
{
    return push(item);
}
template <class T>
typename Stack<T>::iterator Stack<T>::begin()
{
    return element_.rbegin();
}
template <class T>
typename Stack<T>::iterator Stack<T>::end()
{
    return element_.rend();
}
template <class T>
typename Stack<T>::const_iterator Stack<T>::begin() const
{
    return element_.crbegin();
}
template <class T>
typename Stack<T>::const_iterator Stack<T>::end() const
{
    return element_.crend();
}

template <class T>
bool Stack<T>::operator==(Stack<T> item)
{
    if (this->max_size() != item.max_size())
    {
        return false;
    }
    if (this->end() - begin() != item.end() - item.begin())
    {
        return false;
    }
    for (size_t cursor; cursor < element_.size(); cursor++)
    {
        if (this->element_[cursor] != item[cursor])
        {
            return false;
        }
    }
    return true;
}
template <class T>
T Stack<T>::pop()
{
    if (element_.size() == 0)
    {
        throw StackEmpty("Unable to pop, stack is empty.");
    }
    auto res = element_[element_.size() - 1];
    this->element_.pop_back();
    return res;
}
template <class T>
void Stack<T>::resize(size_t t)
{
    if (t < this->max_size() && t < this->element_.size())
    {
        while (this->element_.size() != t)
        {
            this->element_.pop_back();
        }
    }
    try
    {
        this->max_size_ = t;
        this->element_.reserve(t);
    }
    catch (const std::length_error& e)
    {
        throw StackCreationFailed("Max stack size is too big.");
    }
    catch (std::bad_alloc& e)
    {
        throw StackCreationFailed("Allocation failed.");
    }
}
template <class T>
std::ostream& Stack<T>::print(std::ostream& s) const
{
    if (element_.size() > 0)
    {
        s << element_[0];
    }
    for (size_t elem = 1; elem < element_.size(); elem++)
    {
        s << ' ' << element_[elem];
    }
    return s;
}
