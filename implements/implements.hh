#pragma once

template <typename T, typename T2 = T>
concept impl_basic_op = requires(const T& a, const T2& s)
{
    +a;
    -a;
    +s;
    -s;
    a + s;
    a - s;
    a* s;
    a / s;
};

template <typename T, typename T2 = T>
concept impl_bitwise_op = requires(const T& a, const T2& s)
{
    ~a;
    ~s;
    a& s;
    a | s;
    a ^ s;
    a << s;
    a >> s;
};

template <typename T, typename T2 = T>
concept impl_modulo = requires(const T& a, const T2& s)
{
    a % s;
    s % a;
};

template <typename T, typename T2 = T>
concept impl_arith_op =
    impl_basic_op<T, T2> && impl_bitwise_op<T, T2> && impl_modulo<T, T2>;