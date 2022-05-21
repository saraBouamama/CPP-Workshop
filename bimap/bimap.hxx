#pragma once

#include <map>
#include <string>

/********************** INSERT ****************************/
template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T1& v1, const T2& v2)
{
    lhs.insert({ v1, v2 });
    rhs.insert({ v2, v1 });
}

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T2& v1, const T1& v2)
{
    lhs.insert({ v2, v1 });
    rhs.insert({ v1, v2 });
}

/********************* ERASE ******************************/
template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T1& v)
{
    auto to_remove = lhs[v];
    rhs.erase(to_remove);
    lhs.erase(v);
}
template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T2& v)
{
    auto to_remove = rhs[v];
    lhs.erase(to_remove);
    rhs.erase(v);
}
/********************** FIND *********************************/
template <typename T1, typename T2>
typename Bimap<T1, T2>::iteratorT1 Bimap<T1, T2>::find(const T1& v)
{
    return lhs.find(v);
}

template <typename T1, typename T2>
typename Bimap<T1, T2>::iteratorT2 Bimap<T1, T2>::find(const T2& v)
{
    return rhs.find(v);
}
/******************** SIZE ***********************************/
template <typename T1, typename T2>
std::size_t Bimap<T1, T2>::size() const
{
    return lhs.size();
}

/******************** CLEAR *********************************/
template <typename T1, typename T2>
void Bimap<T1, T2>::clear()
{
    lhs.clear();
    rhs.clear();
}
