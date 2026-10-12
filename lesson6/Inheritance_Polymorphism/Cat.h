#pragma once
#include "Animal.h"
#include <string>
#include <iostream>
using namespace std;

class Cat : public Animal
{
	void MakeSound() const override;
	string getType() const;
	friend ostream& operator<<(ostream& os, const Cat& obj);
	~Cat() override;
};

