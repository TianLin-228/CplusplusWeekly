//
// Created by Cu Cui on 2021/9/15.
//
// C++ Weekly - Ep 93 - Custom Comparators for Containers
// C++ Weekly - Ep 94 - Lambdas as Comparators
// std::set
// C++ Containers library std::set
//  Defined in header <set>
//  template<
//    class Key,
//    class Compare = std::less<Key>,
//    class Allocator = std::allocator<Key>
//> class set;

#include <iostream>
#include <string>
#include <set>

struct MyData
{
    std::string val;
    bool operator< (const MyData &data) const {
        return val < data.val;
    }
};

struct NewData
{
    std::string val;
};

struct Compare
{
    bool operator() (const NewData &lhs, const NewData &rhs) const {
        return lhs.val < rhs.val;
    }
};

int main()
{
    std::set<MyData> my_set;
    MyData m1{"lin"};
    MyData m2{"cu"};

    my_set.insert(m1);
    my_set.insert(m2);
    my_set.insert(m2);

    for (auto &m : my_set)
        std::cout << m.val << " ";

    std::set<NewData, Compare> new_set;
    NewData n1{"lin"};
    NewData n2{"cu"};
    new_set.insert(n1);
    new_set.insert(n2);
    new_set.insert(n2);

    for (auto &n : new_set)
        std::cout << n.val << " ";

    std::set new_data{{NewData{"lin"}},
                     [](const NewData &lhs, const NewData &rhs) {
                        return lhs.val < rhs.val;
                     }};

    new_data.insert(n2);

    for (auto &n : new_data)
        std::cout << n.val << " ";


    return 0;
}
