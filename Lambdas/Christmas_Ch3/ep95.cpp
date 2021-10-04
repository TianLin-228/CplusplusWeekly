//
// Created by Cu Cui on 2021/9/16.
//
// C++ Weekly - Ep 95 - Transparent Comparators

#include <iostream>
#include <string>
#include <set>

struct MyData
{
    std::string val;
};

struct Compare
{
    bool operator() (const MyData& lhs, const MyData& rhs) const {
        return lhs.val < rhs.val;
    }

    template<typename T>
    bool operator() (const MyData& lhs, const T& rhs) const {
        return lhs.val < rhs;
    }

    template<typename T>
    bool operator() (const T& lhs, const MyData& rhs) const {
        return lhs < rhs.val;
    }

    using is_transparent = int;
};

int main()
{
    std::set<MyData, Compare> my_data;
    my_data.insert(MyData{"lin"});
    my_data.insert(MyData{"cu"});

    for (auto data : my_data)
        std::cout << data.val << " ";

    std::cout << my_data.count("lin") << std::endl;

    return 0;
}