#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>
#include <vector>
#include "Utils.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Dog::Dog() : breed(""), name(""), age(0), photograph("") {}

Dog::Dog(const string& breed, const string& name, const int& age, const string& photograph)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
}

string Dog::toString()
{
	stringstream ss;
	ss << this->breed<< "," << this->name << "," << this->age << "," << this->photograph << endl;
	return ss.str();
}

void Dog::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
}

istream & operator>>(istream & is, Dog & dog)
{
	//read line
	//split by ","
	//take artist,title,link
	//split 3rd token by ":"
	//take duration
	//set atributes on Song s

	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	string breed, name, photograph;
	int age=0;
	if (tokens.size() == 4)
	{
		breed = tokens[0];
		name = tokens[1];
		stringstream to_int(tokens[2]);
		to_int >> age;
		photograph = tokens[3];
	}
	dog.breed = breed;
	dog.name = name;
	dog.age = age;
	dog.photograph = photograph;
	

	return is;
}

ostream & operator<<(ostream & os, Dog & dog)
{
	os << dog.breed << "," << dog.name << "," << dog.age << "," << dog.photograph <<endl;
	return os;
}
