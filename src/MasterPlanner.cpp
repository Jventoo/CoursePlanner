#include "includes/MasterPlanner.h"

MasterPlanner::MasterPlanner()
{
	currentCat = nullptr;
}

MasterPlanner::~MasterPlanner()
{
	currentCat = nullptr;

	for (auto e : courseCats)
	{
		delete e;
		e = nullptr;
	}
}

void MasterPlanner::addCatalog(CourseCatalog* newCat)
{
	courseCats.push_back(newCat);

	// Update schoolsCombo or find way to tie schoolsCombo to courseCats vector
}

void MasterPlanner::removeCatalog(CourseCatalog* oldCat)
{
	if (courseCats.size() == 0)
		throw nullptr;
	else if (oldCat == currentCat)
		currentCat = nullptr;

	// Improve loop
	auto begin = courseCats.begin(), end = courseCats.end();
	bool found = false;

	while (!found && begin != end)
	{
		if (*(*begin) == *oldCat)
		{
			auto temp = *begin;

			courseCats.erase(begin);
			delete temp;

			temp = nullptr;
			oldCat = nullptr;
			found = true;
		}

		++begin;
	}

	if (!currentCat && courseCats.size() > 0)
		currentCat = courseCats[0];
}

void MasterPlanner::setCurrCatalog(CourseCatalog* newPtr)
{
	currentCat = newPtr;

	// Update course list to selected catalog then do one of following:

	// APPROACH 1

	//for (const auto& e : catalogObj->getCatalog())
	//{
	//	// Create course widget from element e
	//	// auto temp = new PlannedClassWidget(e);

	//	// Populate the following with each new widget
	//	QAbstractListModel* model;
	//	ui.coursesList->setModel(model);
	//}


	// APPROACH 2

	// loop as before
	// inner loop -> create dyn widget, add to scrollbox
	// (slower, more expensive although may be practical on small scale)
}

QString MasterPlanner::getPlanName() const
{
	return planName;
}

void MasterPlanner::setPlanName(const QString& newName)
{
	planName = newName;
}