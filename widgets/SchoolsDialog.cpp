#include "SchoolsDialog.h"

SchoolsDialog::SchoolsDialog(QWidget *parent)
	: QDialog(parent)
{
	entriesAdded = false;

	setupUi(this);
}

SchoolsDialog::~SchoolsDialog()
{
}


void SchoolsDialog::on_addButton_clicked()
{
	auto model = schoolsList->model();
	int i = model->rowCount();

	model->insertRow(i);

	auto index = model->index(i, 0);
	model->setData(index, "");

	schoolsList->setCurrentIndex(index);
	schoolsList->edit(index);

	updateRemoveButton();

	entriesAdded = true;
}

void SchoolsDialog::on_removeButton_clicked()
{
	auto model = schoolsList->model();
	auto i = schoolsList->currentIndex().row();

	model->removeRow(i);

	updateRemoveButton();
}

void SchoolsDialog::on_closeButton_clicked()
{
	if (entriesAdded)
	{
		auto model = schoolsList->model();
		for (int i = 0; i < model->rowCount(); ++i)
		{
			if (model->data(model->index(i, 0)) != "")
				continue;
			else
			{
				model->setData(model->index(i, 0), QStringLiteral("School%1").arg(i));
			}
		}
	}

	accept();
}

bool SchoolsDialog::updateRemoveButton()
{
	bool countGtrOne = schoolsList->model()->rowCount() > 1;
	removeButton->setEnabled(countGtrOne);

	return countGtrOne;
}

void SchoolsDialog::reject()
{
	on_closeButton_clicked();
	QDialog::reject();
}