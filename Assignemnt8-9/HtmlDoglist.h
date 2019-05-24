#pragma once
#include "FileDoglist.h"
#include <string>

class HtmlDoglist : public FileDoglist
{
public:

	void writeToFile() override;
	void displayDoglist() const override;
};
