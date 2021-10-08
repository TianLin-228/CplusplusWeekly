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
    enum {value = Factorial<N-1>::value * N};
};
// base case to break infinite recursion
template<>
struct Factorial<0>
{
    enum {value = 1};
};
// equivalent constexpr function
constexpr int factorial(int n)
{
    return (n > 0) ? (factorial(n-1) * n) : 1;
}

static void v0(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = Factorial<10>::value;
    }
}
static void v1(benchmark::State & state)
{
    int n = state.range(0);
    while(state.KeepRunning())
    {
        res = factorial(n);
    }
    state.SetComplexityN(state.range(0));
}


BENCHMARK(v0);
BENCHMARK(v1)->RangeMultiplier(2)->Range(4,64);

BENCHMARK_MAIN();