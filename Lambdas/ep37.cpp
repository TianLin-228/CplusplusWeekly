//
// Created by Cu Cui on 2021/9/6.
//
// C++ Weekly - Ep 37 - Stateful Lambdas
// generate a Fibonacci sequence using lambda

#include <iostream>

// show how std::exchange works
void helper_function()
{
    int i = 1, j = 2;
    // j -> i, old_i -> j
    j = std::exchange(i, j);
    std::cout << "i = " << i << ", j = " << j << std::endl;
}

int main()
{
    helper_function();
    int count = 0;
    auto fibonacci = [i = 0, j = 1, &count]() mutable {
        i = std::exchange(j, i+j);
        count++;
        return j;};

    for (int i=0; i<10; i++)
        fibonacci();
    std::cout << "Count: " << count+1 << "\n" << fibonacci() << std::endl;

    return 0;
}

