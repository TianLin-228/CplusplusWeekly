//
// Created by Cu Cui on 2021/9/9.
//
// C++ Weekly - Ep 200 - Christmas Class 2019 - Chapter 1 of 5 - Understanding Lambdas
// Exercise

// 1) Come up the reason for wanting lambda to function pointer conversion
// 2) Ponder the practical application of inheriting from lambdas
// 3) [n0=0,n1=1]() mutable {n0 = std::exchange(n1,n0+n1); return n0;}
//     implement in C++98

// 1) Enable lambda to be passed to a function for reusing
//
// 2) "direct access to operator()()"

// 3)

#include <iostream>

class my_Lambda
{
private:
    int n0;
    int n1;
public:
    my_Lambda() : n0(0), n1(1) {}
    constexpr int operator()() {
        int temp = n0;
        n0 = n1;
        n1 = temp + n1;
        return n0;
    }
};


int main()
{
    my_Lambda l;
    for (int i=0; i<10; ++i)
        l();

    std::cout << l() << std::endl;
    return 0;
}
