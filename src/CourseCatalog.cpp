#include "includes/CourseCatalog.h"

CourseCatalog::CourseCatalog()
{

}

void CourseCatalog::addCourse(const Course& newCourse)
{
	// Change insertion to keep sorted order

	catalog.push_back(newCourse);
}

void CourseCatalog::removeCourse(const Course& newCourse)
{
	// Find course, remove from vector. Update sorted order
}

Course* CourseCatalog::findCourse(int crseID) const
{
	// Find course using binary search
	// Update return value to iterator?

	return nullptr;
}

Course* CourseCatalog::findCourse(const std::string& crseName) const
{
	// Find course using binary search
	// Update return value to iterator?

	return nullptr;
}

Section* CourseCatalog::findSection(const std::string& crseName, int secID) const
{
	// Binary search sections vector

	return nullptr;
}

std::vector<Course>& CourseCatalog::getCatalog()
{
	return catalog;
}

std::string CourseCatalog::getSchoolName() const
{
	return schoolName;
}

void CourseCatalog::setSchoolName(const std::string& newName)
{
	schoolName = newName;
}

void CourseCatalog::addPreReqs(const Course& newCourse)
{
	// Add to dynamic vector
}

void CourseCatalog::addPreReqs(const std::vector<int>& preReqs)
{
	// Add to dynamic vector
}

void CourseCatalog::removePreReqs(const Course& newCourse)
{
	// Remove
}

void CourseCatalog::removePreReqs(const std::vector<int>& preReqs)
{
	// Remove
}

bool CourseCatalog::operator==(const CourseCatalog& rhs) const
{
	if (schoolName == rhs.schoolName)
		return true;

	return false;
}