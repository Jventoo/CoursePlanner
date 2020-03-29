#pragma once

#include <QDialog>
#include "ui_AddCourseDialog.h"

class AddCourseDialog : public QDialog, public Ui::AddCourseDialog
{
	Q_OBJECT

public:
	AddCourseDialog(QWidget *parent = Q_NULLPTR);
	~AddCourseDialog();
};
