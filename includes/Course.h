#pragma once

#include <string>
#include <vector>

#include "LocTime.h"
#include "Person.h"
#include "Term.h"

class Course
{
	Course();

private:
	std::string courseName, courseDesc, subject;

	Person instructor;
	Term date;
	LocTime locDetails;

	int credits, crseID, secID;

	/** Stores course IDs */
	std::vector<int> preReqs;
};