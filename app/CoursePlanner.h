#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CoursePlanner.h"
#include "includes/CourseCatalog.h"

class CoursePlanner : public QMainWindow
{
	Q_OBJECT

public:
	CoursePlanner(QWidget *parent = Q_NULLPTR);
	~CoursePlanner();

	void setCatalog(CourseCatalog* newPtr);

private:
	Ui::CoursePlannerClass ui;
	CourseCatalog* catalogObj;
};
