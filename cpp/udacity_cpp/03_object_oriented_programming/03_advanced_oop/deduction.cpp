/*
Exercise: Deduction

In this example, you will see the difference between total and partial deduction.
Deduction occurs when you instantiate an object without explicitly identifying 
the types. Instead, the compiler "deduces" the types. This can be helpful for 
writing code that is generic and can handle a variety of inputs.

OBJECTIVES
Declare a generic conditional function
Use it in conditional sorting
Declare another function which is used for processing generic types (this case 
is print())
*/

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
bool func(T x, T y)
{
    return (x < y);
}

template <typename T>
void print(std::vector<T> v)
{
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<double> v = {9,3,2,32.32,10.323,10.0003,4.9789};
    std::vector<char> v2 = {'a','Z','M','x','Y','c','U'};

    print(v);
    
    // Deducing function return type
    std::sort(v.begin(), v.end(), func<double>);
    print(v);


    // For input parameters as PrintVector we have total deduction,without 
    // specification
    print(v2);
    // this will support any type of that which has defined support for 
    // (in this case) < operator
    std::sort(v2.begin(), v2.end(), func<char>);
    print(v2);
}
