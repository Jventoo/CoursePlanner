#include "includes/Section.h"

Section::Section()
{
	sectionID = 0;
}

void Section::setCrseInst(const Person& newInst)
{
	instructor = newInst;
}

void Section::setCrseTerm(const Term& newTerm)
{
	date = newTerm;
}

void Section::setLocDetails(const LocTime& newDetails)
{
	locDetails = newDetails;
}

void Section::setSecID(int newID)
{
	sectionID = newID;
}

bool Section::operator==(const Section& otherSec)
{
	if (getCourseID() == otherSec.getCourseID() &&
		sectionID == otherSec.sectionID)
		return true;

	return false;
}

bool Section::operator<(const Section& otherSec)
{
	if (sectionID < otherSec.sectionID)
		return true;

	return false;
}

bool Section::operator>(const Section& otherSec)
{
	if (sectionID > otherSec.sectionID)
		return true;

	return false;
}