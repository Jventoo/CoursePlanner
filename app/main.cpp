#include "CoursePlanner.h"
#include "includes/MasterPlanner.h"

#include <QtWidgets/QApplication>
#include <QDataStream>

QDataStream& operator<<(QDataStream& out, Course const& rhs) {
	out.writeRawData(reinterpret_cast<const char*>(&rhs), sizeof(rhs));
	return out;
}

QDataStream& operator>>(QDataStream& in, Course &rhs) {
	in.readRawData(reinterpret_cast<char*>(&rhs), sizeof(rhs));
	return in;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MasterPlanner plan;

	qRegisterMetaTypeStreamOperators<Course>("Course");

	Course csc110("Intro To Computer Science", "CS 110", 4, 10101);
	Course csc210("Computer Science 2", "CS 210", 4, 10102);
	Course csc310("Computer Science 3", "CS 310", 4, 10103);

	plan.addCatalog(new CourseCatalog("Orange Coast College"));
	plan.getCourseCats().at(0)->addCourse(csc110);
	plan.getCourseCats().at(0)->addCourse(csc210);
	plan.getCourseCats().at(0)->addCourse(csc310);

	CoursePlanner w(plan);

	// TO-DO: Populate catalog from saved text files

	w.show();
	return a.exec();
}