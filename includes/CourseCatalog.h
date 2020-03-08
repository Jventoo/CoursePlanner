#pragma once

#include "includes/Course.h"
#include <vector>

class CourseCatalog
{
public:
	CourseCatalog();

private:
	std::vector<Course> Catalog;
};