#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class FileException : public exception
{
private:
	string  message;
public:
	FileException(string message) : message(message) {}
	~FileException() {}

	virtual const char* what()
	{
		return message.c_str();
	}
};

