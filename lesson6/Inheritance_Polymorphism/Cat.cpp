#include "Cat.h"
#include <iostream>
#include <string>
using namespace std;

void Cat::MakeSound() const
{
	std::cout << "Meow!" << std::endl;
}

string Cat::getType() const
{
	return "Cat\0";
}

ostream& operator<<(ostream& os, const Cat& obj)
{
	os << "Cat Value: " << obj.getType();
	return os; // Return the stream for chaining
}

Cat::~Cat() {};