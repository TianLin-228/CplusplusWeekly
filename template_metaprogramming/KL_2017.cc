//
// Created by cucui on 19.10.21.
//

#include <iostream>
#include <type_traits>

template<int N>
struct factorial {
    static const long value =
            N * factorial<N-1>::value;
};
template<>
struct factorial<0> {
    static const long value = 1;
};

template <long N>
constexpr long factorial_v = factorial<N>::value;

template <int N, int K>
struct Binomial {
    static const long val = factorial_v<N> / factorial_v<K> / factorial_v<N-K>;
};

template <int N, typename T>
std::enable_if_t<(N < 0), T> pow(T x) {
    return 1 / pow<-N>(x);
}
template <int N, typename T>
std::enable_if_t<(N == 0), T> pow(T x) {
    return 1;
}
template <int N, typename T>
std::enable_if_t<(N > 0) && (N % 2 == 1), T> pow(T x) {
    return pow<N - 1>(x) * x;
}
template <int N, typename T>
std::enable_if_t<(N > 0) && (N % 2 == 0), T> pow(T x) {
    T p = pow<N/2>(x);
    return p * p;
}


int main()
{
    int x = rand() % 12;
    std::cout << x << " " << pow<4>(x);
    return 0;
//    std::cout << Binomial<15, 2>::val << std::endl;
//    return 0;
}