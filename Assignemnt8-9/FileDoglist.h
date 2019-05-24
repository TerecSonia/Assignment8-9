#pragma once
#include "Doglist.h"
class FileDoglist : public Doglist
{
protected:
	std::string filename;
public:
	FileDoglist();
	virtual ~FileDoglist() {}

	void setFilename(const std::string& filename);
	virtual void writeToFile() = 0;
	virtual void displayDoglist() const = 0;
};

