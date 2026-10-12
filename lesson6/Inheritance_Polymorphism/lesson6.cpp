#include <iostream>
using namespace std;
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dog.h"
#include "Cat.h"

TEST_CASE("testing tha animals") {
	Animal* animals[7];
	animals[0] = new Cat();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Dog();
	animals[4] = new Cat();
	animals[5] = new Dog();
	animals[6] = new Cat();

	for (int i = 0; i < 7; i++) {
		animals[i]->MakeSound();
		std::cout << animals[i]->getType() << std::endl;
	}

	for (int i = 0; i < 7; i++) {
		delete animals[i];
	}

	cout << animals[0] << endl;
}