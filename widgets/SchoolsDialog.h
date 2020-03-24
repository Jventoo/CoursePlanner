#pragma once

#include <QDialog>
#include "ui_SchoolsDialog.h"

class SchoolsDialog : public QDialog, public Ui::SchoolsDialog
{
	Q_OBJECT

public:
	SchoolsDialog(QWidget *parent = Q_NULLPTR);
	~SchoolsDialog();
};
