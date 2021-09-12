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

int main()
{
    print(1,2,3,4,"a","b","cd");
    return 0;
}