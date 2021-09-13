//
// Created by Cu Cui on 2021/9/13.
//
// C++ Weekly - Ep 184 - What Are Higher Order Functions?

#include <iostream>
#include <utility>
#include <cmath>

template<typename F, typename G>
auto f_of_g(F f, G g)
{
    return [f, g](double s){return f(g(s));};
}

double calculation_1(double a)
{
    return std::pow(a, 2);
}

double calculation_2(double s)
{
    return std::sqrt(2) * s;
}

int main()
{
    auto compute = f_of_g(calculation_1, calculation_2);
    std::cout << compute(3) << std::endl;
    return 0;
}
