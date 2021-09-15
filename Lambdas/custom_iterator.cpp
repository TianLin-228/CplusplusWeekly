//
// Created by Cu Cui on 2021/9/15.
//
// Writing a custom iterator in modern C++
// https://internalpointers.com/post/writing-custom-iterators-modern-cpp

#include <iostream>

template<typename T>
class Iterator
{
public:
    explicit Iterator(T* ptr) : my_ptr(ptr) {};
    Iterator() : my_ptr(nullptr) {};
    T& operator*() {
        return *my_ptr;
    };
    Iterator<T> operator++() {
        my_ptr++;
        return *this;
    };
    Iterator<T> operator++(int) {
        Iterator<T> temp = *this;
        my_ptr++;
        return temp;
    };

    friend bool operator== (const Iterator<T>& lhs, const Iterator<T>& rhs) {
        return lhs.my_ptr == rhs.my_ptr;
    };
    friend bool operator!= (const Iterator<T>& lhs, const Iterator<T>& rhs) {
        return lhs.my_ptr != rhs.my_ptr;
    };

private:
    T* my_ptr;
};

template<typename T, int n>
class MyData : public Iterator<T>
{
public:
    MyData() {
        std::cout << "MyData()\n";
        data = new T[n];
        for (int i = 0; i < n; i++)
            data[i] = i * i;
    }
    ~MyData() {
        std::cout << "~MyData()\n";
        delete[] data;
    }

    Iterator<T> begin() {return Iterator<T>(data);}
    Iterator<T> end()   {return Iterator<T>(data + n);}
private:
    T* data;
};

int main()
{

    MyData<int, 10> myData;
    for (auto &item : myData)
        std::cout << item << " ";
    std::cout << std::endl;

    Iterator<int> iterator_begin(myData.begin()),
                  iterator_end(myData.end());
//    iterator_begin = myData.begin();
//    iterator_end = myData.end();

    for (auto it = iterator_begin; it != iterator_end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
