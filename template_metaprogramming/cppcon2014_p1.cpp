//
// Created by Cu Cui on 2021/10/4.
//
// CppCon 2014: Walter E. Brown "Modern Template Metaprogramming: A Compendium, Part I"

#include <iostream>
#include <cmath>
#include "/export/home/cucui/Documents/UniHeidelberg/benchmark/include/benchmark/benchmark.h"

double res;

double v0()
{
    return std::pow(2.3, 100);
}

template <int N>
struct P
{
    static constexpr double x = P<N - 1>::x * 2.3;
};
template <>
struct P<0>
{
    static constexpr double x = 1.;
};

template <int N>
constexpr double x = x<N-1> * 2.3;

template <>
constexpr double x<0> = 1.;

template <int N>
constexpr double vv()
{
    return 2.3 * vv<N - 1>();
}
template <>
constexpr double vv<0>()
{
    return 1.;
}

static void v0(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = v0();
    }
}

static void v1(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = P<100>::x;
    }
}
static void v2(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = x<100>;
    }
}

static void v3(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = vv<100>();
    }
}

BENCHMARK(v0);
BENCHMARK(v1);
BENCHMARK(v2);
BENCHMARK(v3);
BENCHMARK_MAIN();


//int main()
//{
//    const double x = 2.3;
//    std::cout << v0(x) << std::endl
//              << P<100>::x << std::endl;
//    return 0;
//}