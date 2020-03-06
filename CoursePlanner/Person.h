#pragma once

#include <string>
#include <sstream>

class Person
{
public:
	Person();
	Person(const std::string& newFName, 
		const std::string& newLName, 
		const std::string& newTitle);

	void setFName(const std::string& newFName);
	void setLName(const std::string& newLName);
	void setTitle(const std::string& newTitle);

	std::stringstream formatName();

private:
	std::string fName;
	std::string lName;
	std::string title;
};