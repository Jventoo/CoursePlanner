#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CoursePlanner.h"
#include "includes/MasterPlanner.h"

#include <vector>
#include <QString>
#include <QStringListModel>

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

	void createSchoolsDialog();

public slots:
	void updatePlanName();
	void updateBackendCatalogs();
	void updateCourseList();

private slots:
	void on_schoolsCombo_currentIndexChanged(int index);

private:
	Ui::CoursePlannerClass ui;
	MasterPlanner& backendPlan;
	QStringListModel* schoolsModel;
};