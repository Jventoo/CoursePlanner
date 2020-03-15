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

Course* CourseCatalog::findCourse(int crseID)
{
	// Find course using binary search
	// Update return value to iterator?

	return nullptr;
}

Course* CourseCatalog::findCourse(const std::string& crseName)
{
	// Find course using binary search
	// Update return value to iterator?

	return nullptr;
}

Section* CourseCatalog::findSection(const std::string& crseName, int secID)
{
	// Binary search sections vector

	return nullptr;
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