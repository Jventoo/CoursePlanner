#pragma once

#include <QDialog>
#include "ui_CourseDialog.h"

#include "AddCourseDialog.h"
#include "includes/CourseCatalog.h"

class CourseDialog : public QDialog, public Ui::CourseDialog
{
	Q_OBJECT

public:
	CourseDialog(QWidget *parent = Q_NULLPTR);
	~CourseDialog();

	// Returns true if enabled
	bool updateRemoveButton();

public slots:
	void fillCourseList(CourseCatalog* cat, QAbstractItemModel* model);

private slots:
	void on_addButton_clicked();
	void on_removeButton_clicked();

private:
	CourseCatalog* assignedCatalog;
};
