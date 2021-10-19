//
// Created by Cu Cui on 2021/9/12.
//
// C++ Weekly - Ep 49 - Why Inherit From Lambdas?
// C++ Weekly - Ep 134 - The Best Possible Way To Create A Visitor?

#include <iostream>
#include <array>
#include <algorithm>

template <typename ...T>
struct Op : T...
{
//    Ep 134
//    Op(T... t) : T(t)... {}
    using T::operator()...;
};

template <typename ...T>
Op(T...) -> Op<T...>;

int main()
{
    int    total_i = 0;
    double total_d = 0.0;

    std::array<int, 4>    arr_i {1, 2, 3, 4};
    std::array<double, 4> arr_d {1.5, 2.5, 3.5, 4.0};
    std::array<char, 4>   arr_c {'c', 'c', 't', 'l'};

    auto sum_i = [&total_i](int i) { total_i += i; return total_i;};
    auto sum_d = [&total_d](double d) { total_d += d; return total_d;};
    auto print = [](char c) { std::cout << c << " ";};

    Op sum_arr{sum_i, sum_d, print};

    std::for_each(begin(arr_i), end(arr_i), sum_arr);
    std::for_each(begin(arr_d), end(arr_d), sum_arr);
    std::for_each(begin(arr_c), end(arr_c), sum_arr);

    std::cout << total_i << " " << total_d << std::endl;

    return 0;
}
