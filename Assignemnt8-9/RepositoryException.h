#pragma once
using namespace std;
#include <iostream>
class RepositoryException
{
protected:
	string message;
public:
	RepositoryException(string message) : message(message) {}
	RepositoryException() {}
	~RepositoryException() {}
	virtual const char* what()
	{
		return message.c_str();
	}
};
