//
// Created by Cu Cui on 2021/10/18.
//
/**
 * @brief Using Jacobi iteration solve a poission equation with 3 points stencil (1D)
 * in a matrix free way
 * try to use template metaprogramming
 */
#include <iostream>
#include <array>
#include <chrono>

/// Laplace operator (Matrix free)
template <int N>
struct LaplaceOp
{
    const double Tow = 2.;
    const double One = 1.;

    constexpr std::array<double, N> ops(std::array<double,N> src);
     void ops(double *dst, const double *src);
};

template<int N>
constexpr std::array<double, N> LaplaceOp<N>::ops(std::array<double, N> src) {
    std::array<double, N> temp{};

    temp[0] = Tow*src[0] - One*src[1];
    temp[N-1] = Tow*src[N-1] - One*src[N-2];
    for (unsigned i=1; i<N-1; ++i)
        temp[i] = Tow*src[i] - One*src[i-1] - One*src[i+1];

    return temp;
}

template<int N>
 void LaplaceOp<N>::ops(double *dst, const double *src) {

    dst[0] = 2*src[0] - 1*src[1];
    dst[N-1] = 2*src[N-1] - 1*src[N-2];
    for (unsigned i=1; i<N-1; ++i)
        dst[i] = 2*src[i] - 1*src[i-1] - 1*src[i+1];

}

template<int N>
std::array<double, N> f(std::array<double, N> src) {
    std::array<double, N> temp{};

    temp[0] = 2*src[0] - 1*src[1];
    temp[N-1] = 2*src[N-1] - 1*src[N-2];
    for (unsigned i=1; i<N-1; ++i)
        temp[i] = 2*src[i] - 1*src[i-1] - 1*src[i+1];

    return temp;
}


template <typename T>
void print(T t)
{
    for (auto a : t)
        std::cout << a << ", ";
    std::cout << std::endl;
}
int main()
{
    const int N = 300000;
    std::array<double,N> x1{};
    double x2[N], temp[N];
    for (unsigned i=0; i<N; ++i)
        x1[i] = x2[i] = (i * i + (double)N) / N;
    //    print(x);

    LaplaceOp<N> laplaceOp;
    auto start = std::chrono::steady_clock::now();
    for (int i=0; i<10000; ++i)
        x1 = laplaceOp.ops(x1);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Elapsed time in milliseconds: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;


    auto start1 = std::chrono::steady_clock::now();
    for (int i=0; i<10000; ++i)
        laplaceOp.ops(temp,x2);
    auto end1 = std::chrono::steady_clock::now();

    std::cout << "Elapsed time in milliseconds: "
    << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count()
    << " ms" << std::endl;

//    print(x);
    return 0;
}