#pragma once
#include"RepositoryException.h"
class DuplicateSongException : public RepositoryException
{

public:
	DuplicateSongException() {}
	~DuplicateSongException() {}

	virtual const char* what()
	{
		return message.c_str();
	}
};

