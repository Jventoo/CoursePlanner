#pragma once

#include <QString>
#include <sstream>

class Person
{
public:
	Person();
	Person(const QString& newFName, 
		const QString& newLName, 
		const QString& newTitle);

	void setFName(const QString& newFName);
	void setLName(const QString& newLName);
	void setTitle(const QString& newTitle);

	std::stringstream formatName();

private:
	QString fName;
	QString lName;
	QString title;
};