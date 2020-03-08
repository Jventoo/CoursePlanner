#pragma once

#include <string>
#include <vector>

#include "LocTime.h"
#include "Person.h"
#include "Term.h"

class Course
{
	Course();
	Course(const std::string& newName, const std::string& newSubj,
		int newCredits, int newCrseID, int newSecID);

	void setCrseName(const std::string& newName);
	void setCrseDesc(const std::string& newDesc);
	void setCrseSubj(const std::string& newSubj);
	void setCrseInst(const Person& newInst);
	void setCrseTerm(const Term& newTerm);
	void setLocDetails(const LocTime& newDetails);
	void setCredits(int newCredits);
	void setCrseID(int newID);
	void setSecID(int newID);
	void setPreReqs(const std::vector<int> newPreReqs);

	bool operator==(const Course& otherCrse);
	bool operator<(const Course& otherCrse);
	bool operator>(const Course& otherCrse);

private:
	std::string courseName, courseDesc, subject;

	Person instructor;
	Term date;
	LocTime locDetails;

	int credits, crseID, secID;

	/** Stores course IDs */
	std::vector<int> preReqs;
};