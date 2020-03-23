#include "CoursePlanner.h"
#include "includes/MasterPlanner.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MasterPlanner plan;
	CoursePlanner w(plan);

	// TO-DO: Populate catalog from saved text files

	w.show();
	return a.exec();
}