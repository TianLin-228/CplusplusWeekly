//
// Created by cucui on 05.10.21.
//

#include <iostream>
#include <cmath>
#include "/export/home/cucui/Documents/UniHeidelberg/benchmark/include/benchmark/benchmark.h"

// template metaprogramming factorial
int res;

template<int N>
struct Factorial
{
    enum {value = Factorial<N-1>::value + N};
};
// base case to break infinite recursion
template<>
struct Factorial<0>
{
    enum {value = 1};
};
// equivalent constexpr function
constexpr int factorial(const int n)
{
    return (n > 0) ? (factorial(n-1) + n) : 1;
}

static void v0(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = Factorial<500>::value;
    }
}
static void v1(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = factorial(500);
    }
}


BENCHMARK(v0);
BENCHMARK(v1);

BENCHMARK_MAIN();