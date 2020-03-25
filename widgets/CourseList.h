#pragma once

#include <QListView>
#include <includes/Course.h>

class CourseList : public QListView
{
	Q_OBJECT

public:
	explicit CourseList(QWidget* parent = nullptr);

public slots:
	void addCourse(const Course& newCourse);
	//void clearCourse(const Course& oldCourse);
	//void createNewModel();
	//void switchModels();
	void clearAll();
};
