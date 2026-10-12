#include "MyString.h"
#include <iostream>

int MyString::instanceCount = 0;

MyString::MyString() : MyString("", 0)
{
	std::cout << "Default constructor" << std::endl;
}

MyString::MyString(const char* newS, int newSize)
{
	if (newSize > maxLen)
	{
		throw std::length_error("string exceeds maximum length");
	}
	size = newSize;
	data = new char[newSize + 1];
	strcpy_s(data, newSize + 1, newS);
	
	instanceCount++;
	
	std::cout << "Main constructor" << std::endl;
}

MyString::MyString(const MyString& other)
{
	size = other.size;
	data = new char[size + 1];
	strcpy_s(data, size + 1, other.data);

	instanceCount++;

	std::cout << "Copy constructor" << std::endl;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		delete[] data;
		size = other.size;
		data = new char[size + 1];

		if (other.data)
		{
			strcpy_s(data, size + 1, other.data);
		}
		else
		{
			data[0] = '\0'; // if other.data is nullptr
		}

		std::cout << "assignment operator" << std::endl;
	}
	return *this;
}

//MyString::MyString(MyString&& obj) noexcept : data(obj.data), size(obj.size)
MyString::MyString(MyString&&) noexcept
{
	data = nullptr;
	size = 0;
	instanceCount++;

	std::cout << "Move constructor" << std::endl;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other) {
		delete[] data;

		data = other.data;
		size = other.size;

		other.data = nullptr;
		other.size = 0;

		std::cout << "move assignment operator" << std::endl;
	}
	return *this;
}

MyString::~MyString()
{
	delete[] data;
	instanceCount--;

	std::cout << "Destructor" << std::endl;
}

const char* MyString::getData() const
{
	return data;
}

void MyString::setData(const char* newData, int newSize)
{
	if (newSize > maxLen)
	{
		throw std::length_error("string exceeds maximum length");
	}

	delete[] data;
	size = newSize;
	data = new char[newSize + 1];
	strcpy_s(data, newSize + 1, newData);
}

int MyString::getInstanceCount()
{
	return instanceCount;
}

//homework 5
char& MyString::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

const char& MyString::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

bool MyString::operator==(const MyString& other) const
{
	return (data == other.data) && (size == other.size);
}

MyString::operator bool() const
{
	return data && data[0] != '\0';
}

MyString MyString::operator+(const MyString& other) const
{
	MyString result;
	size_t newSize = strlen(data) + strlen(other.data) + 1;
	result.size = newSize;
	result.data = new char[newSize];
	strcpy_s(result.data, newSize, data);
	strcat_s(result.data, newSize, other.data);
	return result;
}

MyString MyString::operator-(int num) const
{
	MyString result;
	if(num>size)
		throw std::out_of_range("Number out of bounds");
	size_t newSize = strlen(data) - num + 1;
	result.size = newSize;
	result.data[newSize] = '\0';
	return result;
}
