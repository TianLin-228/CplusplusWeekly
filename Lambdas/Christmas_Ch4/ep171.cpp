//
// Created by Cu Cui on 2021/9/18.
//
// C++ Weekly - Ep 171 - C++20's Parameter Packs In Captures

#include <iostream>
#include <utility>

template<typename Callable, typename ... Para>
auto my_fun(Callable callable, Para ... para)
{
    return [callable = std::move(callable), ...para = std::move(para)]()
    {
        return callable(para...);
    };
}
int add(int a1, int a2)
{
    return a1 + a2;
}

int main()
{
    std::cout << my_fun(add, 1, 2)() << std::endl;
    return 0;
}