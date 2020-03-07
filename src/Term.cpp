#include "includes/Term.h"
#include <iomanip>

Term::Term()
{
	isSemester = false;
}

void Term::setTermName(const std::string& newName)
{
	termName = newName;
}

void Term::setTermType(bool isSem)
{
	isSemester = isSem;
}

void Term::setStart(const Date& newStart)
{
	startDate = newStart;
}

void Term::setEnd(const Date& newEnd)
{
	endDate = newEnd;
}

void Term::setDuration(const Date& newStart, const Date& newEnd)
{
	setStart(newStart);
	setEnd(newEnd);
}

std::stringstream Term::formatDuration()
{
	std::stringstream ss;

	ss << startDate << " - " << endDate;

	return ss;
}


std::ostream& operator<<(std::ostream& out, const Date& outDate)
{
	out.fill(0);
	out.width(2);
	out << outDate.month << "/"; 
	
	out.width(2);
	out << outDate.day << "/";
	
	out.width(4);
	out << outDate.year;

	return out;
}