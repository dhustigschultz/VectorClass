// VectorClass.cpp : This file contains the 'main' function, which tests the functionality of the MyVector class. 
//

#include <iostream>
#include <string>
#include <iomanip>
#include "MyVector.h"

int main()
{
    const std::size_t numElems1 = 10;
    const std::size_t numElems2 = 20;
    MyVector vec1;

    std::cout << "Size of vec1: " << vec1.size() << '\n';
    std::cout << "Is vec1 empty? " << std::boolalpha << vec1.empty() << '\n' << '\n';

    //Testing push_back on vec1:
    std::cout << "Adding elements to vec1 using push_back: " << '\n';
    for (int i = 0; i < numElems1; ++i) {
        vec1.push_back(static_cast<float>(i));
        std::cout << vec1[i] << " ";
    }
    std::cout << '\n' << '\n';

    std::cout << "Size of vec1: " << vec1.size() << '\n';
    bool isEmpty = vec1.empty();
    std::cout << "Is vec1 empty? " << isEmpty << '\n';
    if (!isEmpty) {
        std::cout << "The first element of vec1 is: " << vec1.front() << '\n';
        std::cout << "The last element of vec1 is: " << vec1.back() << '\n' << '\n';
    }

    MyVector vec2;

    std::cout << "Size of vec2: " << vec2.size() << '\n';
    std::cout << "Is vec2 empty? " << vec2.empty() << '\n' << '\n';

    std::cout << "Adding elements to vec2 using push_back: " << '\n';
    for (int i = 0; i < numElems2; ++i) {
        vec2.push_back(static_cast<float>(i));
        std::cout << vec2[i] << " ";
    }
    std::cout << '\n' << '\n';

    std::cout << "Size of vec2: " << vec2.size() << '\n';
    isEmpty = vec2.empty();
    std::cout << "Is vec2 empty? " << isEmpty << '\n';
    if (!isEmpty) {
        std::cout << "The first element of vec2 is: " << vec2.front() << '\n';
        std::cout << "The last element of vec2 is: " << vec2.back() << '\n' << '\n';
    }

    //Testing the overloaded operator==
    std::cout << "Does vec1 == vec2? " << (vec1 == vec2) << '\n' << '\n';

    //Testing the swap function:
    std::cout << "Swapping vec1 and vec2: " << '\n';
    vec1.swap(vec2);

    std::cout << "Size of vec1: " << vec1.size() << '\n';
    std::cout << "Is vec1 empty? " << vec1.empty() << '\n';
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << '\n' << '\n';

    std::cout << "Size of vec2: " << vec2.size() << '\n';
    std::cout << "Is vec2 empty? " << vec2.empty() << '\n';
    for (int i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << '\n' << '\n';

    //Testing pop_back:
    std::cout << "Using pop_back to remove last element of vec1: " << '\n';
    vec1.pop_back();
    std::cout << "Size of vec1: " << vec1.size() << '\n';
    std::cout << "Is vec1 empty? " << vec1.empty() << '\n';
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << '\n' << '\n';

    //Testing the overloaded operator=:
    std::cout << "Assigning vec2 to vec1: " << '\n';
    vec1 = vec2;

    std::cout << "Size of vec1: " << vec1.size() << '\n';
    std::cout << "Is vec1 empty? " << vec1.empty() << '\n';
    std::cout << "Does vec1 == vec2? " << (vec1 == vec2) << '\n';
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << '\n' << '\n';

    //Testing insert
    vec2.insert(20.5, 5);

    std::cout << "Size of vec2: " << vec2.size() << '\n';
    std::cout << "Is vec2 empty? " << vec2.empty() << '\n';
    for (int i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << '\n' << '\n';

    return 0;

}
