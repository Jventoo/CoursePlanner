#include "CourseList.h"
#include "Widgets/Delegates/CourseDelegate.h"

#include <QStandardItemModel>

CourseList::CourseList(QWidget* parent) :
	QListView(parent)
{
	auto* delegate = new CourseDelegate(this);
	QPalette p(palette());

	p.setBrush(QPalette::WindowText, QColor("#303030"));
	p.setBrush(QPalette::Base, QColor("#F0F1F2"));
	p.setBrush(QPalette::Light, QColor("#FFFFFF"));
	p.setBrush(QPalette::Midlight, QColor("#D3D6D8"));
	p.setBrush(QPalette::Mid, QColor("#C5C9Cb"));
	p.setBrush(QPalette::Dark, QColor("#9AA0A4"));
	p.setBrush(QPalette::Text, QColor("#616b71"));
	p.setBrush(QPalette::Highlight, QColor("#E2E4E5"));

	delegate->setContentsMargins(8, 8, 8, 8);
	delegate->setHorizontalSpacing(8);
	delegate->setVerticalSpacing(4);

	setPalette(p);
	setFont(QFont("MSShellDlg 2", 12));
	setModel(new QStandardItemModel(this));
	setItemDelegate(delegate);
}

void CourseList::addCourse(const Course& newCourse)
{
	QVariant courseData;
	courseData.setValue(newCourse);

	auto* item = new QStandardItem(newCourse.getCourseName());

	item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	item->setData(courseData, Qt::UserRole);

	static_cast<QStandardItemModel*>(model())->appendRow(item);
	scrollToBottom();
}

void CourseList::clearAll()
{
	static_cast<QStandardItemModel*>(model())->clear();
}
