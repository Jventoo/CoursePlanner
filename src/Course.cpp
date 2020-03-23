#include "includes/Course.h"
#include "includes/Section.h"

Course::Course()
{
	// Init dyn mem

	credits = 0;
	crseID = 0;
}

Course::~Course()
{
	/*delete preReqs;
	delete sections;

	preReqs = nullptr;
	sections = nullptr;*/
}

Course::Course(const QString& newName, const QString& newSubj,
	int newCredits, int newCrseID)
{
	// init dyn mem

	courseName = newName;
	subject = newSubj;
	credits = newCredits;
	crseID = newCrseID;
}

int Course::getCrseID() const
{
	return crseID;
}

void Course::setCrseName(const QString& newName)
{
	courseName = newName;
}

void Course::setCrseDesc(const QString& newDesc)
{
	courseDesc = newDesc;
}

void Course::setCrseSubj(const QString& newSubj)
{
	subject = newSubj;
}

void Course::setCredits(int newCredits)
{
	credits = newCredits;
}

void Course::setCrseID(int newID)
{
	crseID = newID;
}

void Course::addPreReq(int newCrseID)
{
	// Search the course catalog for the supplied course ID. Add to preReq array
}

void Course::removePreReq(int newCrseID)
{
	// Search preReq array. Remove found course
}

void Course::setPreReqs(const std::vector<int> newPreReqs)
{
	*preReqs = newPreReqs;
}

int Course::addSection(const Section& newSec)
{
	sections->push_back(newSec);

	return 0;
}

void Course::removeSection(const Section& oldSec)
{
	// Search sections array, remove param sec
}

void Course::removeSection(int oldSecID)
{
	// Search sections array, remove param sec
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