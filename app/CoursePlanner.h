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

public slots:
	void updatePlanName();

private:
	Ui::CoursePlannerClass ui;
	MasterPlanner& backendPlan;
};