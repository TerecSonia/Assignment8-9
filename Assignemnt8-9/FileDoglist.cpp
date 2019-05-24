#include "FileDoglist.h"



FileDoglist::FileDoglist(): Doglist{}, filename{""}
{
}

void FileDoglist::setFilename(const std::string & filename)
{
	this->filename = filename;
}



