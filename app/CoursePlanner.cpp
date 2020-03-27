#include "CoursePlanner.h"
#include "PlannedClassWidget.h"
#include "CourseList.h"
#include "includes/Course.h"
#include "SchoolsDialog.h"

CoursePlanner::CoursePlanner(MasterPlanner& BP, QWidget *parent)
	: backendPlan(BP), QMainWindow(parent)
{
	ui.setupUi(this);

	// Connect Title Line Edit's "editted" signal to slot updating our plan's name
	connect(ui.titleLineEdit, &QLineEdit::editingFinished, 
		this, &CoursePlanner::updatePlanName);

	// Connect "Edit Schools" action to create schoolsDialog
	connect(ui.action_EditSchools, &QAction::triggered,
		this, &CoursePlanner::createSchoolsDialog);

	// If we don't have any course catalogs (i.e. schools), disable combos/buttons
	if (backendPlan.getCourseCats().size() == 0)
	{
		toggleComboTexts();
		toggleCoursesButton();
	}
	else
	{
		auto currCat = backendPlan.getCourseCats().at(0);

		backendPlan.setCurrCatalog(currCat);
		populateCourseList(currCat);
		populateComboBoxes();
	}
}

CoursePlanner::~CoursePlanner()
{
}

void CoursePlanner::toggleComboTexts()
{
	if (!ui.schoolsCombo->isEditable())
	{
		// Disable school and year comboboxes. Set placeholder texts
		ui.schoolsCombo->setEditable(true);
		ui.yearCombo->setEditable(true);

		ui.schoolsCombo->setCurrentText("No Schools Added");
		ui.yearCombo->setCurrentText("N/A");

		ui.schoolsCombo->lineEdit()->setEnabled(false);
		ui.yearCombo->lineEdit()->setEnabled(false);
	}
	else
	{
		ui.schoolsCombo->setEditable(false);
		ui.yearCombo->setEditable(false);
	}
}

void CoursePlanner::toggleCoursesButton()
{
	if (ui.coursesButton->isEnabled())
		ui.coursesButton->setEnabled(false);
	else
		ui.coursesButton->setEnabled(true);
}

void CoursePlanner::updatePlanName()
{
	backendPlan.setPlanName(ui.titleLineEdit->text());
}

// Rough version. Needs refinement
void CoursePlanner::updateBackendCatalogs()
{
	auto& cats = backendPlan.getCourseCats();
	auto catsSize = cats.size();

	auto comboModel = ui.schoolsCombo->model();
	auto comboSize = ui.schoolsCombo->count();
	
	if (catsSize > comboSize) // Items removed and potentially changed. TO-DO: Preserve course catalogs; currently destructs catalogs if removed isn't last index.
	{
		// Check for changes
		for (int i = 0; i < comboSize; ++i)
		{
			auto comboItem = comboModel->data(comboModel->index(i, 0));
			if (comboItem == cats[i]->getSchoolName())
			{
				continue;
			}
			else
			{
				cats[i]->setSchoolName(comboItem.toString());
				cats[i]->getCatalog().clear();
			}
		}

		// Delete excess cats
		for (int i = comboSize; i < catsSize; ++i)
		{
			auto ptr = cats[i];

			cats.erase(cats.begin() + i);

			delete ptr;
			ptr = nullptr;
		}
	}
	else if (catsSize < comboSize) // Items added and potentially changed
	{
		// Check for changes
		for (int i = 0; i < catsSize; ++i)
		{
			auto comboItem = comboModel->data(comboModel->index(i, 0));
			if (comboItem == cats[i]->getSchoolName())
			{
				continue;
			}
			else
			{
				cats[i]->setSchoolName(comboItem.toString());
				cats[i]->getCatalog().clear();
			}
		}

		// Add new cats
		cats.reserve(comboSize);

		for (int i = catsSize; i < comboSize; ++i)
		{
			auto ptr = new CourseCatalog(comboModel->data(comboModel->index(i, 0)).toString());
			cats.push_back(ptr);
		}
	}
	else // Check for renamed items
	{
		for (int i = 0; i < catsSize; ++i)
		{
			auto comboItem = comboModel->data(comboModel->index(i, 0));
			if (comboItem == cats[i]->getSchoolName())
			{
				continue;
			}
			else
			{
				cats[i]->setSchoolName(comboItem.toString());
			}
		}
	}
}

void CoursePlanner::populateCourseList(CourseCatalog* cat)
{
	for (const auto& e : cat->getCatalog())
	{
		ui.coursesList->addCourse(e);
	}
}

void CoursePlanner::populateComboBoxes()
{
	auto currCat = backendPlan.getCurrentCat();

	if (currCat)
	{	
		QStringList list;
		for (const auto& e : backendPlan.getCourseCats())
			list << e->getSchoolName();

		schoolsModel = new QStringListModel(list);

		ui.schoolsCombo->setModel(schoolsModel);
		ui.schoolsCombo->setCurrentText(currCat->getSchoolName());


		// Give functionality to years combo
		ui.yearCombo->setEnabled(false);
	}
	else
		schoolsModel = nullptr;
}

void CoursePlanner::on_schoolsCombo_currentIndexChanged(int index)
{
	backendPlan.setCurrCatalog(backendPlan.getCourseCats().at(index));

	updateCourseList();
}

void CoursePlanner::createSchoolsDialog()
{
	SchoolsDialog dialog(this);
	dialog.schoolsList->setModel(schoolsModel);
	dialog.updateRemoveButton();

	if (dialog.exec())
	{
		updateBackendCatalogs();
		updateCourseList();
	}
}

void CoursePlanner::updateCourseList()
{
	// WIP APPROACH! CHANGE TO CREATE NEW MODEL AND SWITCHING: PRESERVING MODEL SO LONG AS IT IS STILL ALIVE IN BACKEND!
	ui.coursesList->clearAll();
	populateCourseList(backendPlan.getCurrentCat());
}