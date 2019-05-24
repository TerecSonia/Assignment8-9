#pragma once
#include "Repository.h"
#include "Doglist.h"
#include <iostream>
#include "DogValidator.h"
#include "FileDoglist.h"

using namespace std;

class Controller
{
private:
	Repository repo;
	FileDoglist& doglist1;
	FileDoglist& doglist2;
	DogValidator validator;
public:
	///Copy constructor
	Controller(const Repository& r, FileDoglist& dlst1, FileDoglist& dlst2,DogValidator v): repo{r},doglist1{dlst1}, doglist2{ dlst2 },validator{v} {}

	/*Returns the repository of the controller
	IN:-
	OUT:this->repo-Repository
	*/
	Repository getRepo()const { return this->repo; }


	/*Returns the doglist of the controller
	IN:-
	OUT:this->doglist-Doglist
	*/
	Doglist getCSVDogList() const { return this->doglist1; }
	Doglist getHtmlDogList() const { return this->doglist2; }
	

	/*Adds a dog to the repository of the controller
	IN:breed-string,name-string,age-int,photograph-string
	OUT:true-bool (the dog was added)
		false-bool(the dog already exists)
	*/
	bool addDogCtrl(const string& breed, const string& name, const int& age, const string& photograph);

	/*Deletes a dog fro the repository of the controller
	IN:name-string,age-int
	OUT:true-bool (the dog was deletes)
		false-bool(the dog doesn't exist)
	*/
	bool deleteDogCtrl(const string& name, const int& age);

	/*Updates a dog from the repository of the controller
	IN:name-string,age-int
	OUT:true-bool (the dog was updated)
		false-bool(the dog doesn't exist)
	*/
	bool updateDogCtrl(const string& name, const int& age, const Dog& dog);

	/*Adds a dog to the doglist of the controller
	IN:dog-Dog
	OUT:-
	*/
	void addDogToDoglist(const Dog& dog,string s);

	/*
		Saves the playlist.
		Throws: FileException - if the given file cannot be opened.
	*/
	void saveDoglist(const std::string& filename,string s);

	/*
	Opens the playlist, with an appropriate application.
	Throws: FileException - if the given file cannot be opened.
	*/
	void openPlaylist(string s) const;

};


