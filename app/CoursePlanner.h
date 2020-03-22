#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CoursePlanner.h"
#include "includes/CourseCatalog.h"

#include <vector>
#include <string>

class CoursePlanner : public QMainWindow
{
	Q_OBJECT

public:
	CoursePlanner(QWidget *parent = Q_NULLPTR);
	~CoursePlanner();

private:
	Ui::CoursePlannerClass ui;
};
