#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CoursePlanner.h"
#include "includes/MasterPlanner.h"

#include <vector>
#include <string>

class CoursePlanner : public QMainWindow
{
	Q_OBJECT

public:
	CoursePlanner(MasterPlanner& BP, QWidget *parent = Q_NULLPTR);
	~CoursePlanner();

public slots:
	void updatePlanName();

private:
	Ui::CoursePlannerClass ui;
	MasterPlanner& backendPlan;
};
