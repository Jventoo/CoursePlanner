#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CoursePlanner.h"

class CoursePlanner : public QMainWindow
{
	Q_OBJECT

public:
	CoursePlanner(QWidget *parent = Q_NULLPTR);

private:
	Ui::CoursePlannerClass ui;
};
