#include "includes/Course.h"
#include "includes/Section.h"

Course::Course()
{
	credits = 0;
	courseID = 0;
}

Course::~Course()
{
	for (auto& e : sections)
	{
		delete e;
		e = nullptr;
	}
}

Course::Course(const QString& newName, const QString& newSubj,
	int newCredits, int newCrseID)
{
	// init dyn mem

	courseName = newName;
	subject = newSubj;
	credits = newCredits;
	courseID = newCrseID;
}

Course::Course(const Course& other)
{
	courseName = other.courseName;
	courseDesc = other.courseDesc;
	subject = other.subject;

	credits = other.credits;
	courseID = other.courseID;

	preReqs = other.preReqs;

	for (auto e : other.sections)
	{
		auto temp = new Section(*e);
		sections.push_back(temp);
	}

}

QString Course::getCourseName() const
{
	return courseName;
}

QString Course::getCourseSubject() const
{
	return subject;
}

QString Course::getCourseDesc() const
{
	return courseDesc;
}

int Course::getCourseCredits() const
{
	return credits;
}

int Course::getCourseID() const
{
	return courseID;
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
	courseID = newID;
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
	preReqs = newPreReqs;
}

int Course::addSection(const Section& newSec)
{
	//sections->push_back(newSec);

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
	if (courseID == otherCrse.courseID)
		return true;
	else if (courseName == otherCrse.courseName)
		return true;
	else
		return false;
}

bool Course::operator<(const Course& otherCrse)
{
	if (courseID < otherCrse.courseID)
		return true;
	else if (courseName < otherCrse.courseName)
		return true;
	else
		return false;
}

bool Course::operator>(const Course& otherCrse)
{
	if (courseID > otherCrse.courseID)
		return true;
	else if (courseName > otherCrse.courseName)
		return true;
	else
		return false;
}