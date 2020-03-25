#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CoursePlanner.h"
#include "includes/MasterPlanner.h"

#include <vector>
#include <QString>

class CoursePlanner : public QMainWindow
{
	Q_OBJECT

public:
	CoursePlanner(MasterPlanner& BP, QWidget *parent = Q_NULLPTR);
	~CoursePlanner();

	void toggleComboTexts();
	void toggleCoursesButton();

	void populateCourseList(CourseCatalog* cat);
	void populateComboBoxes();

public slots:
	void updatePlanName();

private:
	Ui::CoursePlannerClass ui;
	MasterPlanner& backendPlan;
};