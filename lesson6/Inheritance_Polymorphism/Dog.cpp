#include "Dog.h"
#include <string>
#include <iostream>
using namespace std;

void Dog::MakeSound() const
{
	std::cout << "Woof!" << std::endl;
}

string Dog::getType() const
{
	return "Dog\0";
}

ostream& operator<<(ostream& os, const Dog& obj)
{
	os << "Dog Value: " << obj.getType();
	return os; // Return the stream for chaining
}

Dog::~Dog() {};