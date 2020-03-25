#pragma once

#include "includes/Course.h"
#include "includes/Section.h"

#include <vector>
#include <QString>

class CourseCatalog
{
public:
	CourseCatalog();
	CourseCatalog(const QString& newName);

	void addCourse(const Course& newCourse);
	void removeCourse(const Course& newCourse);
	
	Course* findCourse(int crseID) const;
	Course* findCourse(const QString& crseName) const;
	Section* findSection(const QString& crseName, int secID) const;

	std::vector<Course>& getCatalog();
	QString getSchoolName() const;

	void setSchoolName(const QString& newName);

	void addPreReqs(const Course& newCourse);
	void addPreReqs(const std::vector<int>& preReqs);
	void removePreReqs(const Course& newCourse);
	void removePreReqs(const std::vector<int>& preReqs);

	bool operator==(const CourseCatalog& rhs) const;

private:
	std::vector<Course> catalog;
	QString schoolName;
};