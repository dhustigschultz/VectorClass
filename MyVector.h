#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include <iostream>
#include <memory>
#include <algorithm>
#include <utility>

class MyVector {
	std::size_t length;
	std::unique_ptr<float[]> buffer;
	// ToDo: include a 'capacity' member, to improve efficiency.
	//(i.e., no need to reallocate memory for the vector every time an element is added)

public:
	//Constructor
	MyVector() : length(0), buffer(std::make_unique<float[]>(length)) {}
	MyVector(std::size_t length) : length(length), buffer(std::make_unique<float[]>(length)) {}

	//Need to create my own (move) operator=, as the compiler in Visual Studio seems to be declaring the default and assiging it to 'delete' if I don't write my own.
	//Consequently, I'm following the 'Rule of 5': https://en.cppreference.com/w/cpp/language/rule_of_three
	//
	// Since unique_ptr deallocates its own memory when it leaves scope, I'm using a simple default destructor.
	~MyVector() = default; 

	MyVector(MyVector const& other) : length(other.length), buffer(std::make_unique<float[]>(other.length)) { //Copy constructor
		for (int i = 0; i < other.length; ++i) {
			buffer[i] = other.buffer[i];
		}
	}
	MyVector(MyVector&& other) noexcept : length(other.length), buffer(std::move(other.buffer)) {} //Move constructor
	MyVector& operator=(MyVector const& other) noexcept; //Copy assignment
	MyVector& operator=(MyVector&& other) noexcept; //Move assignment
	
	float& front();
	const float& front() const;
	float& back();
	const float& back() const;

	std::size_t size() const;
	bool empty() const;

	//ToDo: add an 'at' function.

	//Overloading operator[]. 
	float& operator[](std::size_t i);
	const float& operator[](std::size_t i) const;

	//ToDo: implement the other comparison operators. 
	bool operator==(const MyVector& rhs);

	void swap(MyVector& other);
	void swap(MyVector& lhs, MyVector& rhs);

	void reallocate(std::size_t n);

	void push_back(float value);
	void pop_back();

	void insert(float value, std::size_t i);

	//ToDo: investigate whether it is possible, using unique_ptr, to write iterator functions such as begin(), end(), cbegin(), etc.

};

#endif
