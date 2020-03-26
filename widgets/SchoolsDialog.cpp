#include "SchoolsDialog.h"

SchoolsDialog::SchoolsDialog(QWidget *parent)
	: QDialog(parent)
{
	allEntriesNormal = false;

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
	model->setData(model->index(i, 0), "");
}

void SchoolsDialog::on_removeButton_clicked()
{
	updateRemoveButton();
}

void SchoolsDialog::on_closeButton_clicked()
{
	if (!allEntriesNormal)
	{
		auto model = schoolsList->model();
		for (int i = 0; i < model->rowCount(); ++i)
		{
			if (model->data(model->index(i, 0)) != "")
				continue;
			else
			{
				model->setData(model->index(i, 0), tr("School" + i));
			}
		}
	}

	accept();
}

bool SchoolsDialog::updateRemoveButton()
{
	bool temp = schoolsList->model()->rowCount() > 1;
	removeButton->setEnabled(temp);

	return temp;
}