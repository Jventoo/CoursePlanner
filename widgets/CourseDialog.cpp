#include "CourseDialog.h"
#include "AddCourseDialog.h"

#include "includes/Course.h"

CourseDialog::CourseDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	assignedCatalog = nullptr;

	//addedCoursesList->setDragEnabled(false);
	//addedCoursesList->setAcceptDrops(false);
}

CourseDialog::~CourseDialog()
{
}

bool CourseDialog::updateRemoveButton()
{
	bool countGtrOne = addedCoursesList->model()->rowCount() > 1;
	removeButton->setEnabled(countGtrOne);

	return countGtrOne;

	return true;
}

void CourseDialog::fillCourseList(CourseCatalog* cat, QAbstractItemModel* model)
{
	addedCoursesList->setModel(model);
	assignedCatalog = cat;
}

void CourseDialog::on_addButton_clicked()
{
	AddCourseDialog addDialog(this);

	if (addDialog.exec())
	{
		Course newCourse;
		newCourse.setCrseName(addDialog.nameEdit->text());
		addedCoursesList->addCourse(newCourse);
	}

	updateRemoveButton();
}

void CourseDialog::on_removeButton_clicked()
{
	auto model = addedCoursesList->model();
	auto i = addedCoursesList->currentIndex().row();

	model->removeRow(i);

	updateRemoveButton();
}