#pragma once

template <bool Cond, typename T>

struct enable_if
{};

template <typename T>
struct enable_if<true, T>
{
    using type = T;
};
