//
// Created by Cu Cui on 2021/9/12.
//
// Variadic function

#include <iostream>

using std::cout;


void print()
{
    cout << "End!\n";
}

template<class A, class... B>
void print(A a, B... b)
{
    cout << a << " ";
    print(b...);
}

template<typename ...S>
auto sum(S... s)
{
    return ([s](){cout << s << " "; return s;}() + ...);
//    return (s + ...);
}

int main()
{
    print(1,2,3,4,"a","b","cd");
    cout << sum(1,2,3,4,5,6) << "\n";
    return 0;
}