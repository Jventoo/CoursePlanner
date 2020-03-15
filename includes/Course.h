#pragma once

#include <string>
#include <vector>

#include "LocTime.h"
#include "Person.h"
#include "Term.h"

class Section;

class Course
{
public:
	Course();
	Course(const std::string& newName, const std::string& newSubj,
		int newCredits, int newCrseID);

	~Course();

	int getCrseID() const;

	void setCrseName(const std::string& newName);
	void setCrseDesc(const std::string& newDesc);
	void setCrseSubj(const std::string& newSubj);
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
	std::string courseName, courseDesc, subject;

	int credits, crseID;

	/** Stores course IDs */
	std::vector<int>* preReqs;
	std::vector<Course>* sections;
};