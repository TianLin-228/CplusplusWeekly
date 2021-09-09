//
// Created by cucui on 09.09.21.
//
// C++ Weekly - Ep 51 - Advanced Stateful Lambdas
//

#include <iostream>
#include <utility>

int main()
{
    auto fibonacci = [a = 0, b = 1]() mutable {
        struct Result {
            int &a;
            int &b;

            Result next(int num = 1) {
                while (num > 0) {
                    a = std::exchange(b, a+b);
                    --num;
                }
                return *this;
            }
            operator int() {
                return a;
            }
        };
        return Result{a, b}.next();
    };

    std::cout << fibonacci().next(10) << std::endl;
    return 0;
}