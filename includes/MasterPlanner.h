#pragma once

#include "includes/CourseCatalog.h"

#include <vector>
#include <QString>

class MasterPlanner
{
public:
	MasterPlanner();
	~MasterPlanner();

	void addCatalog(CourseCatalog* newCat);
	void removeCatalog(CourseCatalog* oldCat);
	void setCurrCatalog(CourseCatalog* newPtr);

	QString getPlanName() const;
	void setPlanName(const QString& newName);

	std::vector<CourseCatalog*>& getCourseCats();

private:
	std::vector<CourseCatalog*> courseCats;
	CourseCatalog* currentCat;

	QString planName;
};
