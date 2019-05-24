#pragma once
#include "Dog.h"
#include <vector>

class Doglist
{
protected:
	vector<Dog> dogs;
	int currentPos;
public:
	///Default constructor
	Doglist();

	/*Adds a dog to the adoption list
	IN:d-Dog
	OUT:-
	*/
	void add(const Dog& d);

	/*Returns all the dogs from the adoption list
	IN:-
	OUT: this->dogs-DynamicVector<Dog>
	*/
	vector<Dog> getDogs() const { return this->dogs; }

	/*Returns the current dog
	IN:-
	OUT:Dog
	*/
	Dog getCurrentDog();
};

