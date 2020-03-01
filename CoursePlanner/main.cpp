#include "CoursePlanner.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CoursePlanner w;
	w.show();
	return a.exec();
}
