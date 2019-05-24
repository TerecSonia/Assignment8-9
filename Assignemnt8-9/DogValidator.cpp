#include "DogValidator.h"

vector<string> DogException::getErrors() const
{
	return this->errors;
}

void DogValidator::validate(const Dog & d)
{
	vector<string> errors;
	if (d.getName().size() < 3)
		errors.push_back("Name must have at least 3 chars.\n");
	if (!isupper(d.getName()[0]))
		errors.push_back("The dog name must start with a capital letter.\n");
	if (d.getAge() < 0)
		errors.push_back("The age must be a valid number.\n");

	if (errors.size() > 0)
		throw DogException(errors);
}