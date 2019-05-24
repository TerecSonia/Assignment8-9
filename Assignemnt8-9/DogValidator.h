#pragma once
#include "Dog.h"
#include <vector>
#include <string>

using namespace std;

class DogException
{
private:
	vector<string> errors;

public:
	DogException(vector<string> _errors) : errors(_errors) {}
	vector<string> getErrors() const;
};

class DogValidator
{
public:
	DogValidator() {}
	void validate(const Dog& d);
};
