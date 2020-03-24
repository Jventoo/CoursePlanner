#pragma once

#include <QDialog>
#include "ui_CourseDialog.h"

class CourseDialog : public QDialog, public Ui::CourseDialog
{
	Q_OBJECT

public:
	CourseDialog(QWidget *parent = Q_NULLPTR);
	~CourseDialog();
};
