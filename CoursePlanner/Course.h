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
	std::string courseName;
	std::string courseDesc;
	std::string subject;

	std::vector<int> preReqs;

	Person instructor;
	Term date;
	LocTime locDetails;

	int credits;
	int crseID;
};