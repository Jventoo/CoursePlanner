#pragma once

#include "includes/CourseCatalog.h"

#include <vector>
#include <string>

class MasterPlanner
{
public:
	MasterPlanner();
	~MasterPlanner();

	void addCatalog(CourseCatalog* newCat);
	void removeCatalog(CourseCatalog* oldCat);
	void setCurrCatalog(CourseCatalog* newPtr);

private:
	std::vector<CourseCatalog*> courseCats;
	CourseCatalog* currentCat;
};
