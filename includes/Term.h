#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include "LocTime.h"

// Format MM/DD/YYYY
struct Date
{
	Date() : month(00), day(00), year(0000) {};

	friend std::ostream& operator<<(std::ostream& out, const Date& outDate);

	int month, day, year;
};

class Term
{
public:
	Term();

	void setTermName(const std::string& newName);
	void setTermType(bool isSem);
	void setStart(const Date& newStart);
	void setEnd(const Date& newEnd);
	void setDuration(const Date& newStart, const Date& newEnd);

	std::stringstream formatDuration();


private:
	std::string termName;
	
	Date startDate;
	Date endDate;

	bool isSemester;
};