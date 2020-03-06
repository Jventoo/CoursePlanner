#include "includes/Person.h"

Person::Person()
{
}

Person::Person(const std::string& newFName,
	const std::string& newLName,
	const std::string& newTitle)
{
	fName = newFName;
	lName = newLName;
	title = newTitle;
}

void Person::setFName(const std::string& newFName)
{
	fName = newFName;
}

void Person::setLName(const std::string& newLName)
{
	lName = newLName;
}

void Person::setTitle(const std::string& newTitle)
{
	title = newTitle;
}


std::stringstream Person::formatName()
{
	std::stringstream ss;

	ss << title << ". " << fName << " " << lName;

	return ss;
}
