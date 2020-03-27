#pragma once

#include <QDialog>
#include "ui_SchoolsDialog.h"

class SchoolsDialog : public QDialog, public Ui::SchoolsDialog
{
	Q_OBJECT

public:
	SchoolsDialog(QWidget *parent = Q_NULLPTR);
	~SchoolsDialog();

	// Returns true if enabled
	bool updateRemoveButton();

public slots:
	void reject();

private slots:
	void on_addButton_clicked();
	void on_removeButton_clicked();
	void on_closeButton_clicked();

private:
	bool entriesAdded;
};
