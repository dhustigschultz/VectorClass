#include "MyVector.h"

//ToDo: add some exception handling, where needed. 

MyVector& MyVector::operator=(MyVector const& other) noexcept {
	buffer.reset(new float[other.length]);
	for (int i = 0; i < other.length; ++i) {
		buffer[i] = other.buffer[i];
	}
	length = other.length;
	return *this;
}

MyVector& MyVector::operator=(MyVector&& other) noexcept {
	buffer = std::move(other.buffer);
	length = other.length;
	return *this;
}

float& MyVector::front() {
	return buffer[0];
}

const float& MyVector::front() const {
	return buffer[0];
}

float& MyVector::back() {
	return buffer[length - 1];
}

const float& MyVector::back() const {
	return buffer[length - 1];
}

std::size_t MyVector::size() const {
	return length;
}

bool MyVector::empty() const {
	return length == 0;
}

float& MyVector::operator[](std::size_t i) {
	return buffer[i];
}

const float& MyVector::operator[](std::size_t i) const {
	return buffer[i];
}

bool MyVector::operator==(const MyVector& rhs) {
	if (length != rhs.length)
		return false;

	for (int i = 0; i < length; ++i)
		if (buffer[i] != rhs.buffer[i])
			return false;

	return true;
}

//This function is used to simplify the swap() and reallocate() functions below.
void MyVector::swap(MyVector& other) {
	std::swap(length, other.length);
	std::swap(buffer, other.buffer);
}

void MyVector::swap(MyVector& lhs, MyVector& rhs) {
	lhs.swap(rhs);
}

//ToDo: add exception handling here, to move back everything in case of some failure. 
void MyVector::reallocate(std::size_t n) {

	if (n > length) {
		MyVector temp(n);

		for (int i = 0; i < length; ++i) {
			temp[i] = buffer[i];
		}

		swap(temp);
	}
	
}

void MyVector::push_back(float value) {
	reallocate(length + 1);
	buffer[length-1] = value;
}

void MyVector::pop_back() {
	--length;
}

void MyVector::insert(float value, std::size_t i) {
	if (i >= 0 && i < length) {
		push_back(0);		// increase the size of the vector by 1

		// move all elements from i to end of vector up one position, 
		// starting at the end of the vector, so we don't overwrite any values.
		for (std::size_t j = length - 1; j > i; --j)
			buffer[j] = buffer[j - 1];

		//put value into the buffer at location i
		buffer[i] = value;
	}
}