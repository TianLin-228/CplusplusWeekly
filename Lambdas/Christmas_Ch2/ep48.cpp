//
// Created by Cu Cui on 2021/9/12.
//
// C++ Weekly - Ep 48 - C++17's Variadic `using`

#include <utility>
#include <memory>
#include <iostream>

template<typename A, typename B>
struct Merge : public A, B
{
public:
    Merge(A a, B b) : A(a), B(b) {}
    using A::operator();
    using B::operator();
};

template<typename ...B>
struct Merge_More : B...
{
    Merge_More(B... b) : B(b)...{}
    using B::operator()...;
};


int main()
{
    auto a = []() {return 10;};
    auto b = [](int val) {return val * val;};
    auto c = [](double val) {return val * 10;};
    auto d = [](char c){ return c;};

    Merge merge(a, b);
    std::cout << merge() << " " << merge(9) << std::endl;

    Merge_More mergeMore(a, b, c, d);
    std::cout << mergeMore() << " "
              << mergeMore(9) << " "
              << mergeMore(1.11) << " "
              << mergeMore('E') << std::endl;

    return 0;
}
