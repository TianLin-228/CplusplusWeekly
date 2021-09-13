//
// Created by Cu Cui on 2021/9/13.
//
// Chapter 2 exercise


#include <iostream>

//Explain the difference between

template<typename First, typename Second>
struct pair_1 {
    First first;
    Second second;
};

template<typename First, typename Second>
struct pair_2 {
    template<typename First_, typename Second_>
    pair_2(First_ &&first_, Second_ &&second_) :
    first(std::forward<First_>(first_)),
    second(std::forward<Second_>(second_))
    {
    }

    First first;
    Second second;
};

struct Helper {
    Helper() { std::puts("Helper()"); }
    ~Helper() { std::puts("~Helper()"); }
    Helper(const Helper &) { std::puts("Helper(const Helper &)"); }
    Helper(Helper &&) { std::puts("Helper(Helper &&)"); }
    Helper &operator=(const Helper &) { std::puts("operator=(const Helper &)"); return *this; }
    Helper &operator=(Helper &&) { std::puts("operator=(Helper &&)"); return *this; }
};

int main()
{
    std::cout << "pair1: \n";
    pair_1<Helper, Helper> pair1{Helper{}, Helper{}};
    std::cout << "\npair2: \n";
    pair_2<Helper, Helper> pair2{Helper{}, Helper{}};
    return 0;
}
