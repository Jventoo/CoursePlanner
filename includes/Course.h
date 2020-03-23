#pragma once

#include <QString>
#include <vector>

#include "LocTime.h"
#include "Person.h"
#include "Term.h"

class Section;

class Course
{
public:
	Course();
	Course(const QString& newName, const QString& newSubj,
		int newCredits, int newCrseID);

	~Course();

	int getCrseID() const;

	void setCrseName(const QString& newName);
	void setCrseDesc(const QString& newDesc);
	void setCrseSubj(const QString& newSubj);
	void setCredits(int newCredits);
	void setCrseID(int newID);

	void addPreReq(int crseID);
	void removePreReq(int crseID);
	void setPreReqs(const std::vector<int> newPreReqs);

	// Returns section ID of new section
	int addSection(const Section& newSec);
	void removeSection(const Section& sec);
	void removeSection(int secID);

	bool operator==(const Course& otherCrse);
	bool operator<(const Course& otherCrse);
	bool operator>(const Course& otherCrse);

private:
	QString courseName, courseDesc, subject;

	int credits, crseID;

	/** Stores course IDs */
	std::vector<int>* preReqs;
	std::vector<Course>* sections;
};