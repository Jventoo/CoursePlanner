#include "includes/Person.h"

Person::Person()
{
	title = "NULL";
}

Person::Person(const QString& newFName,
	const QString& newLName,
	const QString& newTitle)
{
	fName = newFName;
	lName = newLName;
	title = newTitle;
}

void Person::setFName(const QString& newFName)
{
	fName = newFName;
}

void Person::setLName(const QString& newLName)
{
	lName = newLName;
}

void Person::setTitle(const QString& newTitle)
{
	title = newTitle;
}


std::stringstream Person::formatName()
{
	std::stringstream ss;

	if (title != "NULL")
		ss << title.toStdString() << ". ";
	ss << fName.toStdString() << " " << lName.toStdString();

	return ss;
}
