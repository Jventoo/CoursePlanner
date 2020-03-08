#include "includes/Course.h"

Course::Course()
{
	credits = 0;
	crseID = 0;
	secID = 0;
}

Course::Course(const std::string& newName, const std::string& newSubj,
	int newCredits, int newCrseID, int newSecID)
{
	courseName = newName;
	subject = newSubj;
	credits = newCredits;
	crseID = newCrseID;
	secID = newSecID;
}

void Course::setCrseName(const std::string& newName)
{
	courseName = newName;
}

void Course::setCrseDesc(const std::string& newDesc)
{
	courseDesc = newDesc;
}

void Course::setCrseSubj(const std::string& newSubj)
{
	subject = newSubj;
}

void Course::setCrseInst(const Person& newInst)
{
	instructor = newInst;
}

void Course::setCrseTerm(const Term& newTerm)
{
	date = newTerm;
}

void Course::setLocDetails(const LocTime& newDetails)
{
	locDetails = newDetails;
}

void Course::setCredits(int newCredits)
{
	credits = newCredits;
}

void Course::setCrseID(int newID)
{
	crseID = newID;
}

void Course::setSecID(int newID)
{
	secID = newID;
}

void Course::setPreReqs(const std::vector<int> newPreReqs)
{
	preReqs = newPreReqs;
}

bool Course::operator==(const Course& otherCrse)
{
	if (crseID == otherCrse.crseID)
		return true;
	else if (courseName == otherCrse.courseName)
		return true;
	else
		return false;
}

bool Course::operator<(const Course& otherCrse)
{
	if (crseID < otherCrse.crseID)
		return true;
	else if (courseName < otherCrse.courseName)
		return true;
	else
		return false;
}

bool Course::operator>(const Course& otherCrse)
{
	if (crseID > otherCrse.crseID)
		return true;
	else if (courseName > otherCrse.courseName)
		return true;
	else
		return false;
}