//
// Created by Cu Cui on 2021/10/31.
//
/**
 * Sum Factorization
 * A = A1 x ... x Ad
 */

#include <iostream>
#include <memory>
#ifdef __linux__
#include "/export/home/cucui/Documents/UniHeidelberg/benchmark/include/benchmark/benchmark.h"
#else
#include <benchmark/benchmark.h>
#endif
#include "tools.h"

const int N = 7;

template <typename T>
void initA(T &A, T &a1, T &a2)
{
    for (int i=0; i<N*N; i+=N)
        for (int j=0; j<N*N; j+=N)
            for (int k=0; k<N; ++k)
                for (int l=0; l<N; ++l)
                    A[(i*N+k*N)*N+j+l] = a1[i+j/N] * a2[k*N+l];
}

template <typename T>
void initX(T &X)
{
    for (int i=0; i<N*N; ++i)
        X[i] = i / N + 1;
}

template <typename T>
void matmul_v0(const T &A, const T &X, T &out)
{
    for (int i=0; i<N*N; ++i)
        for (int j=0; j<N*N; ++j)
            out[i] += A[i*N*N+j] * X[j];
}

template <typename T>
void matmul_v1(const T &a1, const T &a2, const T &X, T &out)
{
    for (int i=0; i<N; ++i) {
        // A2 * x
        auto z = std::make_unique<double[]>(N);
        for (int j=0; j<N; ++j)
            for (int k=0; k<N; ++k)
                z[j] += a2[j*N+k] * X[i*N+k];
        // update out
        for (int j=0; j<N; ++j)
            for (int k=0; k<N; ++k)
                out[j*N+k] += a1[j*N+i] * z[k];
    }
}
//int main()
//{
//    auto A1 = std::make_unique<double[]>(N*N);
//    auto A2 = std::make_unique<double[]>(N*N);
//    auto A  = std::make_unique<double[]>(N*N*N*N);
//    auto X  = std::make_unique<double[]>(N*N);
//    auto out1 = std::make_unique<double[]>(N*N);
//    auto out2 = std::make_unique<double[]>(N*N);
//
//    init(A1, N*N);
//    init(A2, N*N);
//    initA(A,A1,A2);
//    initX(X);
//
//    matmul_v0(A, X, out1);
//    matmul_v1(A1, A2, X, out2);
//    print_vector(std::forward<decltype(out1)>(out1), N*N);
//    print_vector(std::forward<decltype(out2)>(out2), N*N);
//    print_vector(std::forward<decltype(A)>(A), N*N*N*N);
//    print_vector(std::forward<decltype(X)>(X), N*N);
//
//}

auto A1 = std::make_unique<double[]>(N * N);
auto A2 = std::make_unique<double[]>(N * N);
auto A = std::make_unique<double[]>(N * N * N * N);
auto X = std::make_unique<double[]>(N * N);
auto out1 = std::make_unique<double[]>(N * N);
auto out2 = std::make_unique<double[]>(N * N);

static void v0(benchmark::State &state)
{
    init(A1, N*N);
    init(A2, N*N);
    initA(A, A1, A2);
    initX(X);
    while(state.KeepRunning())
        matmul_v0(A, X, out1);
}

static void v1(benchmark::State &state)
{
    init(A1, N*N);
    init(A2, N*N);
    initX(X);
    while(state.KeepRunning())
        matmul_v1(A1, A2, X, out2);
}

BENCHMARK(v0);
BENCHMARK(v1);

BENCHMARK_MAIN();