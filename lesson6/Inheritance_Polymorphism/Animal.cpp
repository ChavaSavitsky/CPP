#include "Animal.h"
#include <string>
#include <iostream>
using namespace std;

string Animal::getType() const {
	return "unknown animal\0";
}

ostream& operator<<(ostream& os, const Animal& obj)
{
	os << "Animal Value: " << obj.getType();
	return os; // Return the stream for chaining
}

Animal::~Animal() {};