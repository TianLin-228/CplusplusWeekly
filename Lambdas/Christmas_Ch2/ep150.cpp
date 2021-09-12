//
// Created by Cu Cui on 2021/9/11.
//
// C++ Weekly - Ep 150 - C++20's Lambdas For Resource Management
// unique_prt included

#include <iostream>
#include <memory>

int main()
{
    auto deleter = [](FILE *f) { std::cout << "deleter\n"; fclose(f);};
    std::cout << "Fopen using unique_ptr\n";
    auto file = std::unique_ptr<FILE, decltype(deleter)>(fopen("demo.txt","w"));
    return 0;
}