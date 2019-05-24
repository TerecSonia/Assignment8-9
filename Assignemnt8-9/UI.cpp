#include "UI.h"
#include <string>
#include <fstream>
#include "FileException.h"
#include "DuplicateSongException.h"

using namespace std;


void UI::printMenu()
{
	cout << endl;
	cout << "1 Administrator mode." << endl;
	cout << "2 User mode." << endl;
	cout << "0 Exit." << endl;
}

void UI::printRepositoryMenu()
{
	cout << endl;
	cout << "1 Add dog." << endl;
	cout << "2 View all dogs." << endl;
	cout << "3 Delete dog." << endl;
	cout << "4 Update dog." << endl;
	cout << "0 Return." << endl;

}

void UI::printAdoptionListMenu()
{
	cout << endl;
	cout << "1 See all dogs one by one." << endl;
	cout << "2 See all the dogs of a given breed, having an age less than a given number." << endl;
	cout << "3 See the adoption list." << endl;
	cout << "4-Save adoption list in file." << endl;
	cout << "5-Open the adoption list " << endl;
	cout << "0 Return." << endl;
}

void UI::addDogUI()
{
	cout << "Enter the breed: ";
	string breed;
	getline(cin, breed);
	cout << "Enter the name: ";
	string name;
	getline(cin, name);
	cout << "Enter the age: ";
	int age;
	cin >> age;
	cin.ignore();
	cout << "Enter the photograph link: ";
	string photograph;
	getline(cin, photograph);
	cout << endl;

	/*bool ok = this->ctrl.addDogCtrl(breed, name, age, photograph);
	if (ok == true)
		cout << "The dog was succesfully added;" << endl;
	else
		cout << "The dog already exists in the list;" << endl;*/
	try {
		this->ctrl.addDogCtrl(breed, name, age, photograph);
	}
	catch (DogException ex)
	{
		for (auto s : ex.getErrors())
			cout << s;
	}
	catch (FileException exc)
	{
		cout << exc.what();
	}
	catch (DuplicateSongException ex)
	{
		cout << ex.what() << endl;
	}
}


void UI::deleteDogUI()
{
	cout << "Enter the name: ";
	string name;
	getline(cin, name);
	cout << "Enter the age: ";
	int age;
	cin >> age;
	
	cout << endl;
	bool ok = this->ctrl.deleteDogCtrl(name, age);
	if (ok == true)
		cout << "The dog was succesfully deleted;" << endl;
	else
		cout << "The dog doesn't exist in the list;" << endl;
}



void UI::updateDogUI()
{
	cout << "Enter the name and age of the dog you want to update:" << endl;
	cout << "Enter the name: ";
	string name;
	getline(cin, name);
	cout << "Enter the age: ";
	int age;
	cin >> age;
	cin.ignore();
	cout << "Enter the new information to update the dog:" << endl;
	cout << "Enter the breed: ";
	string breed1;
	getline(cin, breed1);
	///cin >>breed1;
	cout << "Enter the name: ";
	string name1;
	getline(cin, name1);
	///cin >> name1;
	cout << "Enter the age: ";
	int age1;
	cin >> age1;
	cin.ignore();
	cout << "Enter the photograph link: ";
	string photograph1;
	getline(cin, photograph1);

	Dog dog{ breed1,name1,age1,photograph1 };
	bool ok = this->ctrl.updateDogCtrl(name, age, dog);
	cout << endl;
	if (ok == true)
		cout << "The dog was succesfully updated;" << endl;
	else
		cout << "The dog doesn't exist in the list;" << endl;

}


void UI::printAllDogs()
{
	/*vector<Dog> v = this->ctrl.getRepo().getDogs();

	if (v.size() == 0)
	{
		cout << "There are no dogs to view." << endl;
		return;
	}

	for (auto dog:v)
	{
		cout << dog.getBreed() << "," << dog.getName() << "," << dog.getAge() << "," << dog.getPhotograph() << endl;
	}*/
	/*string filename = "dogs.txt";
	ofstream f(filename, ofstream::out);

	for (auto fc : v)
	{
		f << fc;
	}
	f.close();*/
	this->ctrl.getRepo().writeFromFile("dogs.txt");
}

void UI::printAdoptionMenu()
{
	cout << endl;
	cout << "1 Adopt dog." << endl;
	cout << "2 Not adopt the dog-Next dog." << endl;
	cout << "0 Exit." << endl;
}

void UI::seeAllDogsOneByOne()
{
	int ok = -1;
	int i = 0;
	Dog d = this->ctrl.getRepo().getDogs()[i];
	cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << ";" << endl;
	d.play();
	UI::printAdoptionMenu();
	int option{ 0 };
	cout << "Input the command: ";
	cin >> option;
	cin.ignore();
	while (ok = -1)
	{

		if (option == 0)
		{
			ok = 0;
			break;
		}
		if (option == 1)
		{
			if (i == this->ctrl.getRepo().getDogs().size() - 1)
				i = 0;

			this->ctrl.addDogToDoglist(d,this->fileType);
			this->ctrl.deleteDogCtrl(d.getName(), d.getAge());
			cout << "The dog was added to the adoption list." << endl;
			cout << endl;
			d = this->ctrl.getRepo().getDogs()[i];
			cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << ";" << endl;
			///d.play();
			UI::printAdoptionMenu();
			option = 0;
			cout << "Input the command: ";
			cin >> option;
			cin.ignore();

		}

		if (option == 2)
		{
			if (i == this->ctrl.getRepo().getDogs().size() - 1)
				i = -1;

			cout << "The dog wasn't added to the adoption list. The next dog is shown. " << endl;
			cout << endl;
			d = this->ctrl.getRepo().getDogs()[++i];
			cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << ";" << endl;
			d.play();
			UI::printAdoptionMenu();
			option = 0;
			cout << "Input the command: ";
			cin >> option;
			cin.ignore();

		}


	}
}

void UI::seeAllDogsByBreedAndAge()
{
	string breed;
	cout << "Enter the breed: ";
	getline(cin, breed);
	int age;
	cout << "Enter the age: ";
	cin >> age;
	cin.ignore();
	if (breed == "")
		this->seeAllDogsOneByOne();

	vector<Dog> dogs;
	for (auto dog : this->ctrl.getRepo().getDogs())
		if (dog.getBreed() == breed && dog.getAge() < age)
			dogs.push_back(dog);
	
	int ok = -1;
	int i = 0;
	Dog d = dogs[i];
	cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << ";" << endl;
	d.play();
	UI::printAdoptionMenu();
	int option{ 0 };
	cout << "Input the command: ";
	cin >> option;
	cin.ignore();
	while (ok = -1)
	{

		if (option == 0)
		{
			ok = 0;
			break;
		}
		if (option == 1)
		{
			if (i == dogs.size() - 1)
				i = 0;

			this->ctrl.addDogToDoglist(d,this->fileType);
			dogs.erase(dogs.begin() + i);
			cout << "The dog was added to the adoption list." << endl;
			cout << endl;
			d = dogs[i];
			cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << ";" << endl;
			d.play();
			UI::printAdoptionMenu();
			option = 0;
			cout << "Input the command: ";
			cin >> option;
			cin.ignore();

		}

		if (option == 2)
		{
			if (i == dogs.size() - 1)
				i = -1;

			cout << "The dog wasn't added to the adoption list. The next dog is shown. " << endl;
			cout << endl;
			d = dogs[++i];
			cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << ";" << endl;
			///d.play();
			UI::printAdoptionMenu();
			option = 0;
			cout << "Input the command: ";
			cin >> option;
			cin.ignore();

		}


	}

}

void UI::printAdoptionList()
{
	vector<Dog> v;
	if (this->fileType == "c")
		v = this->ctrl.getCSVDogList().getDogs();
	else
		v = this->ctrl.getHtmlDogList().getDogs();
	if (v.size() == 0)
	{
		cout << "There are no dogs to adopt." << endl;
		return;
	}

	for (auto d: v)
	{
		cout << d.getBreed() << " - " << d.getName() << "; " << d.getAge() << ";" << d.getPhotograph() << endl;
	}
}

void UI::writeAdoptionListInFile()
{
	if (this->fileType == "c")
		this->ctrl.saveDoglist("Doglist.csv", this->fileType);
	else
		this->ctrl.saveDoglist("Doglist.html", this->fileType);
	
}

void UI::openAdoptionList()
{
	this->ctrl.openPlaylist(this->fileType);
}


void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
	
		if (command == 0)
			break;

		// administrator mode
		if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
		
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addDogUI();
					break;
				case 2:
					this->printAllDogs();
					break;
				case 3:
					this->deleteDogUI();
					break;
				case 4:
					this->updateDogUI();
					break;
				}
			}
		}

		///User mode
		if (command == 2)
		{
			while (true)
			{
				UI::printAdoptionListMenu();
				int commandUser{ 0 };
				cout << "Input the command: ";
				cin >> commandUser;
				cin.ignore();
				if (commandUser == 0)
					break;
				switch (commandUser)
				{
				case 1:
					this->seeAllDogsOneByOne();
					break;
				case 2:
					this->seeAllDogsByBreedAndAge();
					break;
				case 3:
					this->printAdoptionList();
					break;
				case 4:
					this->writeAdoptionListInFile();
					break;
				case 5:
					this->openAdoptionList();
					break;

				}

			}
		}

	}
}
