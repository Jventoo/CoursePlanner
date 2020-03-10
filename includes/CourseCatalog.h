#pragma once

#include "includes/Course.h"
#include "includes/Section.h"
#include <vector>
#include <string>

class CourseCatalog
{
public:
	CourseCatalog();

	void addCourse(const Course& newCourse);
	void removeCourse(const Course& newCourse);
	
	Course* findCourse(int crseID);
	Course* findCourse(const std::string& crseName);
	Section* findSection(const std::string& crseName, int secID);

	void addPreReqs(const Course& newCourse);
	void addPreReqs(const std::vector<int>& preReqs);
	void removePreReqs(const Course& newCourse);
	void removePreReqs(const std::vector<int>& preReqs);

	

private:
	std::vector<Course> catalog;
};