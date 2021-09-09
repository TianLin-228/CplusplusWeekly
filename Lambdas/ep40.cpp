//
// Created by cucui on 09.09.21.
//
// C++ Weekly - Ep 40 - Inheriting for Lambdas
//

#include <iostream>
#include <functional>

template<typename L1, typename L2>
struct S : L1, L2
{
    S(L1 l1, L2 l2) : L1(std::move(l1)), L2(std::move(l2)) {}
    using L1::operator();
    using L2::operator();
};

class my_L1
{
public:
    my_L1() : val(5) {}
    int val;
    int operator() (){
        return val;
    }
};

class my_L2
{
public:
    my_L2(int a) : val(a) {}
    int val;
    int operator() (int a){
        return a * a;
    }
};

class COMBINE : public my_L1, my_L2
{
public:
    COMBINE(my_L1 l1, my_L2 l2) : my_L1(l1), my_L2(l2) {}
    using my_L1::operator();
    using my_L2::operator();
};

int main()
{
//    auto l1 = []() { return 5;};
//    auto l2 = [](int a) { return a * a;};

//    auto combine = S(l1, l2);

    my_L1 l1;
    my_L2 l2(10);
    COMBINE combine(l1, l2);
    std::cout << combine() << " " << combine(10) << std::endl;

    return 0;
}
