//
// Created by Cu Cui on 2021/10/4.
//
// CppCon 2014: Walter E. Brown "Modern Template Metaprogramming: A Compendium, Part I"

#include <iostream>
#include <cmath>
#include <benchmark/benchmark.h>


// ------------ pow -----------------
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

//BENCHMARK(v0);
//BENCHMARK(v1);
//BENCHMARK(v2);
//BENCHMARK(v3);



// ------------- abs -------------
template <int N>
struct Abs
{
    static_assert(N!=INT_MIN);
    static constexpr int value = (N > 0) ? N : -N;
};

static void w0(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = Abs<-100>::value;
    }
}

static void w1(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = std::abs(-100);
    }
}


//BENCHMARK(w0);
//BENCHMARK(w1);

// --------- gcd --------------
template <int M, int N>
struct Gcd
{
    static constexpr int value = Gcd<N, M%N>::value;
};
template<int M>
struct Gcd<M, 0>
{
    static_assert(M!=0);
    static constexpr int value = M;
};

constexpr int gcd_fun(const int M, const int N)
{
    return (N > 0) ? gcd_fun(N, M%N) : M;
}



static void g0(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = Gcd<3190011, 3803181>::value;
    }
}

static void g1(benchmark::State & state)
{
    while(state.KeepRunning())
    {
        res = gcd_fun(3190011, 3803181);
    }
}

//BENCHMARK(g0);
//BENCHMARK(g1);
//BENCHMARK_MAIN();

// -------- rank -------------
template <typename T>
struct rank{
    static const size_t value = 0u;
};

template <typename U, int N>
struct rank<U[N]>{
    static const size_t value = 1u + rank<U>::value;
};







int main()
{
    const double x = 2.3;
    std::cout << rank<int>::value << std::endl
              << rank<int[10][10][20]>::value << std::endl;
    return 0;
}