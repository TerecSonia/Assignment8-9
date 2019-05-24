#include "Repository.h"
#include <assert.h>
#include <vector>
#include <algorithm>
#include "FileException.h"
#include "DuplicateSongException.h"

using namespace std;

int Repository::findByNameAndAge(const string & name, const int & age)
{
	for (int i=0;i<this->dogs.size();i++)
	{
		if (this->dogs[i].getName() == name && this->dogs[i].getAge() == age)
			return i;
	}
	return -1;
}

bool Repository::addDog(const Dog& dog)
{
	if (findByNameAndAge(dog.getName(), dog.getAge()) != -1)
		throw DuplicateSongException();
	this->dogs.push_back(dog);
	return true;
	
	return false;
}


bool Repository::deleteDog(const string& name, const int& age)
{
	int index = findByNameAndAge(name, age);
	if (index != -1)
	{
		this->dogs.erase(this->dogs.begin()+index);
		return true;
	}
	return false;

}

bool Repository::updateDog(const string & name, const int & age, const Dog & dog)
{
	int index = findByNameAndAge(name, age);
	if (index != -1)
	{
		this->dogs[index] = dog;
		return true;
	}
	return false;
}

void Repository::readFromFile(string filename)
{
	Dog d;
	ifstream f(filename, ifstream::in);

	if (!f.is_open())
		throw FileException("File could not be opened!");

	while (f >> d)
	{
		this->dogs.push_back(d);
	}
	f.close();
}

void Repository::writeFromFile(string filename)
{
	ofstream f(filename, ofstream::out);

	if (!f.is_open())
		throw FileException("File could not be opened!");

	for (auto dog : this->dogs)
	{
		f << dog;
	}
	f.close();
}


