#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
	string fileType;

public:
	///Copy constructor
	UI(const Controller& c, string s) : ctrl(c), fileType{ s } {}

	void run();

private:
	
	///Prints the Menu
	static void printMenu();

	///Prints the Administrator Menu
	static void printRepositoryMenu();

	///Prints the User Menu
	static void printAdoptionListMenu();

	///Add a dog to the list
	void addDogUI();

	///Deletes a dog from the list
	void deleteDogUI();
	void updateDogUI();

	///Prints all dogs
	void printAllDogs();

	void printAdoptionMenu();

	///See all dogs one by one
	void seeAllDogsOneByOne();

	///See all dogs of a given breed having an age less than a given number
	void seeAllDogsByBreedAndAge();

	///See the adoption list
	void printAdoptionList();
	void writeAdoptionListInFile();
	void openAdoptionList();
};

