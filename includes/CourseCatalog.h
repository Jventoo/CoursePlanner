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
	
	Course* findCourse(int crseID) const;
	Course* findCourse(const std::string& crseName) const;
	Section* findSection(const std::string& crseName, int secID) const;

	std::vector<Course>& getCatalog();
	std::string getSchoolName() const;

	void setSchoolName(const std::string& newName);

	void addPreReqs(const Course& newCourse);
	void addPreReqs(const std::vector<int>& preReqs);
	void removePreReqs(const Course& newCourse);
	void removePreReqs(const std::vector<int>& preReqs);

	bool operator==(const CourseCatalog& rhs) const;

private:
	std::vector<Course> catalog;
	std::string schoolName;
};