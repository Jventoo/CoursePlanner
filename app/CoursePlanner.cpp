#include "CoursePlanner.h"
#include "PlannedClassWidget.h"
#include "CourseList.h"
#include "includes/Course.h"

CoursePlanner::CoursePlanner(MasterPlanner& BP, QWidget *parent)
	: backendPlan(BP), QMainWindow(parent)
{
	ui.setupUi(this);

	// Connect Title Line Edit's "editted" signal to slot updating our plan's name
	connect(ui.titleLineEdit, &QLineEdit::editingFinished, 
		this, &CoursePlanner::updatePlanName);

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
		for (const auto& e : backendPlan.getCourseCats())
			ui.schoolsCombo->addItem(e->getSchoolName());

		ui.schoolsCombo->setCurrentText(currCat->getSchoolName());


		// Give functionality to years combo
		ui.yearCombo->setEnabled(false);
	}
}