#include "Dog.h"
#include "UI.h"
#include <Windows.h>
#include <fstream>
#include "CSVDoglist.h"
#include "HtmlDoglist.h"
#include "FileDoglist.h"

using namespace std;

int main()
{
	Repository repo{};
	DogValidator validator{};
	repo.readFromFile("dogRead.txt");
	cout << "CSV or HTML? c-CSV; h-HTML: ";
	string choice;
	getline(cin, choice);
	CSVDoglist doglist1;
	HtmlDoglist doglist2;
	Controller ctrl{ repo,doglist1,doglist2,validator };
	UI ui{ ctrl ,choice};
	ui.run();

	return 0;
}