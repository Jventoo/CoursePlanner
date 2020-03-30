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

	/*setSelectionMode(QAbstractItemView::SingleSelection);
	setDragEnabled(true);
	setAcceptDrops(true);
	setDropIndicatorShown(true);
	setDragDropMode(QAbstractItemView::DragDrop);
	setDefaultDropAction(Qt::TargetMoveAction);
	setMovement(QListView::Free);*/
}

void CourseList::addCourse(const Course& newCourse)
{
	auto* item = new QStandardItem(newCourse.getCourseName());

	QVariant courseData;
	courseData.setValue(newCourse);

	item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable 
		| Qt::ItemIsDropEnabled | Qt::ItemIsDragEnabled);
	item->setData(courseData, Qt::UserRole);

	static_cast<QStandardItemModel*>(model())->appendRow(item);
	scrollToBottom();
}

void CourseList::clearCourse(const Course& newCourse)
{
	auto modl = static_cast<QStandardItemModel*>(model());
	QStandardItem* currItem = modl->itemFromIndex(currentIndex());

	if (currItem)
	{
		auto rw = currItem->row();
		auto del = modl->takeRow(rw);
		
		for (auto& e : del)
			delete e;

		/*auto cnt = count();

		if (cnt > 0)
			if (row == 0)
				setCurrentRow(row);
			else
				setCurrentRow(row - 1);
		*/
	}
}

void CourseList::clearAll()
{
	static_cast<QStandardItemModel*>(model())->clear();
}

void CourseList::switchModels(QAbstractItemModel* newModel)
{
	setModel(newModel);
}