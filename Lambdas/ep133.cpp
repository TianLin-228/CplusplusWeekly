//
// Created by Cu Cui on 2021/9/6.
//
// C++ Weekly - Ep 133 - What Exactly IS A Lambda Anyhow?
// implement lambda

#include<cstdio>
#include<iostream>
#include<utility>

// implement lambda
struct my_lambda {
    my_lambda(int a) {val = a;}
    int val;

    template<typename T>
    constexpr auto operator()(T i) {
        std::cout << "Hello from my lambda!\n";
        return ++val + i;
    }
};


int main()
{
    int val = 10;
    my_lambda l(val);
    auto f = [val](auto i) mutable {std::cout << "Hello from lambda!\n"; return ++val + i;};

    std::cout << "lambda result:\n"    << f(2.1) << std::endl
              << "my lambda result:\n" << l(2.1) << std::endl;

    return 0;
}
