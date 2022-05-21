#include "exist.hh"

template <class T>

bool Exist<T>::operator()(T t)
{
    for (auto position : vector_)
    {
        if (position == t)
            return true;
    }
    vector_.push_back(t);
    return false;
}
