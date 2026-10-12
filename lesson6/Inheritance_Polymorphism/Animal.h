#pragma once
#include <string>
#include <iostream>
using namespace std;

class Animal
{
	public:
		virtual void MakeSound() const = 0;
		string getType() const;
		friend ostream& operator<<(ostream& os, const Animal& obj);
		virtual ~Animal();
};
