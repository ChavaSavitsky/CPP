#pragma once
#include "Animal.h"
#include <string>
#include <iostream>
using namespace std;

class Dog : public Animal
{
	void MakeSound() const override;
	string getType() const;
	friend ostream& operator<<(ostream& os, const Dog& obj);
	~Dog() override;
};

