#pragma once

#include "Course.h"

class Section : public Course
{
public:
	Section();

	void setCrseInst(const Person& newInst);
	void setCrseTerm(const Term& newTerm);
	void setLocDetails(const LocTime& newDetails);

	void setSecID(int newID);

	bool operator==(const Section& otherSec);
	bool operator<(const Section& otherSec);
	bool operator>(const Section& otherSec);

private:
	Person instructor;
	Term date;
	LocTime locDetails;

	int sectionID;
};