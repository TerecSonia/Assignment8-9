#include "Controller.h"
#include <assert.h>

//Controller::Controller(const Repository & repo,  FileDoglist & doglist,DogValidator validator)
//{
//	this->repo = repo;
//	this->doglist = doglist;
//	this->validator = validator;
//}

bool Controller::addDogCtrl(const string& breed, const string& name, const int& age, const string& photograph)
{
	Dog dog{ breed,name,age,photograph };
	this->validator.validate(dog);

	return this->repo.addDog(dog);
}

bool Controller::deleteDogCtrl(const string & name, const int & age)
{
	return this->repo.deleteDog(name, age);
}

bool Controller::updateDogCtrl(const string & name, const int & age, const Dog & dog)
{
	return this->repo.updateDog(name, age, dog);
}

void Controller::addDogToDoglist(const Dog & dog,string s)
{
	if (s=="c")
		this->doglist1.add(dog);
	else
		this->doglist2.add(dog);
	  
}

void Controller::saveDoglist(const std::string & filename,string s)
{
	if (s == "c")
	{
		this->doglist1.setFilename(filename);
		this->doglist1.writeToFile();
	}
	else
	{
		this->doglist2.setFilename(filename);
		this->doglist2.writeToFile();
	}
}

void Controller::openPlaylist(string s) const
{
	if (s=="c")
		this->doglist1.displayDoglist();
	else
		this->doglist2.displayDoglist();
}


