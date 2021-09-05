//
// Created by Cu Cui on 2021/9/5.
//
// C++ code to demonstrate the working of for_each loop
//

/*
  Syntax
  for_each (InputIterator start_iter, InputIterator last_iter, Function fnc)

    start_iter : The beginning position
    from where function operations has to be executed.
    last_iter : The ending position
    till where function has to be executed.
    fnc/obj_fnc : The 3rd argument is a function or
    an object function which operation would be applied to each element.
*/


#include<iostream>
#include<algorithm>

// helper function
void print_array(int a)
{
    std::cout << a << " ";
}

void plus_one(int &a)
{
    a++;
}


// helper object
struct Square {
    void operator() (int a)
    {
        std::cout << a * a << " ";
    }
} obj;

void ex1()
{
    int arr[6] = {1, 3, 5, 2, 4, 6};
    std::cout << "Print array using for_each: " << std::endl;
    std::for_each(arr, arr + 6, print_array);
    std::cout << std::endl;
    std::cout << "Print array using for_each with (i+1)^2 : " << std::endl;
    std::for_each(arr, arr + 6, plus_one);

    std::for_each(arr, arr + 6, obj);
    std::cout << std::endl;
}

// C++ code to demonstrate the working of for_each with Exception

void print_odd(int a)
{
    if (a % 2 == 0)
    {
        throw a;
    }
    std::cout << a << " ";
}
void ex2()
{
    int arr[6] = {1, 3, 5, 2, 4, 6};
    std::cout << "Print array using for_each with Exception: " << std::endl;
    try {
        std::for_each(arr, arr + 6, print_odd);
    }
    catch (int i) {
        std::cout << "\nThe Exception element is : " << i << "\n";
    }
    std::cout << std::endl;
}

void ex3()
{
    int arr[6] = {1, 3, 5, 2, 4, 6};
    std::cout << "Print array using for_each with lambda: " << std::endl;

    std::for_each(arr, arr + 6, [](int &a) {++a;});

    std::for_each(arr, arr + 6, [](int a) {std::cout << a << " ";});
    std::cout << "\n";

}

int main()
{
    ex1();
    ex2();
    ex3();

    return 0;
}


