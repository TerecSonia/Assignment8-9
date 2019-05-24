#include "CSVDoglist.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryException.h"
#include "FileException.h"

using namespace std;

void CSVDoglist::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	for (auto s : this->dogs)
		f << s;

	f.close();
}

void CSVDoglist::displayDoglist() const
{
	//string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
	////ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	//ShellExecuteA(NULL, NULL, "c:\WINDOWS\system32\\notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "notepad.exe", this->filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}
