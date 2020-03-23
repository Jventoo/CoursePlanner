#include "CoursePlanner.h"
#include "PlannedClassWidget.h"
//#include "includes/Course.h"

CoursePlanner::CoursePlanner(MasterPlanner& BP, QWidget *parent)
	: backendPlan(BP), QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.titleLineEdit, &QLineEdit::editingFinished, 
		this, &CoursePlanner::updatePlanName);
}

CoursePlanner::~CoursePlanner()
{
}

void CoursePlanner::updatePlanName()
{
	backendPlan.setPlanName((ui.titleLineEdit->text).toStdString());
}