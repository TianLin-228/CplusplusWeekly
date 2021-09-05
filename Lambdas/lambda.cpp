//
// Created by Cu Cui on 2021/9/5.
//
// Lambda expression in C++

/*
    [ capture clause ] (parameters) -> return-type
    {
        definition of method
    }

 */

#include<iostream>

int main()
{
    int arr[] = {1, 3, 5, 2, 4};
    auto square = [](int i) {return i * i;};

    std::cout << "Square using lambda:\n"
                 "10^2 = " << square(10) << "\n";

    auto print_arr = [arr]() {
        std::for_each(arr, arr+5, [](int i) {std::cout << i << " ";});
    };

    print_arr();

    return 0;
}