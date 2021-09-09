//
// Created by Cu Cui on 2021/9/9.
//
// C++ Weekly - Ep 97 - Lambda To Function Pointer Conversion
//

#include <set>
#include <string>
#include <functional>
#include <vector>

struct Person
{
    std::string name;
};



int main()
{
    auto comparator = [](const Person &p1, const Person &p2) {return p1.name < p2.name;};
    using fp = bool (*)(const Person &p1, const Person &p2);

    fp my_FP = comparator;

    std::set<Person, fp> set(comparator);

    std::vector<int (*)(int, int)> ops;
    ops.emplace_back([](int i, int j) {return i + j;});
    ops.emplace_back([](int i, int j) {return i * j;});

    return 0;
}
