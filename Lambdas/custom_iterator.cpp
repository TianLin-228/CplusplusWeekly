//
// Created by Cu Cui on 2021/9/15.
//
// Writing a custom iterator in modern C++
// https://internalpointers.com/post/writing-custom-iterators-modern-cpp

#include <iostream>

class Iterator
{
public:

};

class MyData
{
public:
    MyData(unsigned int N) {
        std::cout << "MyData()\n";
        data = new int[N];}
    ~MyData() {
        std::cout << "~MyData()\n";
        delete[] data; }
private:
    int* data;
};

int main()
{
    MyData myData(10);
    return 0;
}
