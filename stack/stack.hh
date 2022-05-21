#pragma once

#include <iostream>
#include <string>
#include <vector>

template <class T>
class Stack
{
public:
    using const_iterator = typename std::vector<T>::const_reverse_iterator;
    using iterator = typename std::vector<T>::reverse_iterator;

    Stack(size_t max_size = 100);

    Stack<T>& push(const T& item);
    Stack<T>& operator+=(const T item);
    Stack<T>& operator<<(const T item);

    T pop();
    T operator--();

    T operator[](size_t i);
    bool operator==(Stack<T> item);

    std::ostream& print(std::ostream& s) const;

    const_iterator begin() const;
    iterator begin();

    const_iterator end() const;
    iterator end();

    void size(size_t t);
    size_t max_size() const;

private:
    size_t max_size_;
    std::vector<T> element_;
};
template <class T>
inline std::ostream& operator<<(std::ostream& ostr, const Stack<T>& p)
{
    return p.print(ostr);
}

#include "stack.hxx"
