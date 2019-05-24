#include <Windows.h>
#include "RepositoryException.h"
#include "FileException.h"
#include "HtmlDoglist.h"
#include "FileDoglist.h"
#include <fstream>

using namespace std;

void HtmlDoglist::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");

	f << "<!DOCTYPE html>" << endl;
	f << "<html>" << endl;
	f << "<head>" << endl;
	f << "<title>Doglist</title>" << endl;
	f << "</head>" << endl;
	f << "<body>" << endl;
	f << "<table border='1'>" << endl;
	f << "<tr>" << endl;
	f << "<td>Breed</td>" << endl;
	f << "<td>Name</td>" << endl;
	f << "<td>Age</td>" << endl;
	f << "<td>Photohraph</td>" << endl;


	for (auto s : this->dogs)
	{
		f << "<tr>" << endl;
		f << "<td>"<<s.getBreed()<<"</td>" << endl;
		f << "<td>" << s.getName() << "</td>" << endl;
		f << "<td>" << s.getAge() << "</td>" << endl;
		f << "<td><a href='" << s.getPhotograph() << "'>Link</a></td>" << endl;
		f << "</tr>" << endl;
	}
	f << "</table>" << endl;
	f << "</body>" << endl;
	f << "</html>" << endl;

	f.close();
}

void HtmlDoglist::displayDoglist() const
{
	//string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
	////ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	//ShellExecuteA(NULL, NULL, "c:\WINDOWS\system32\\notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "chrome.exe", this->filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}