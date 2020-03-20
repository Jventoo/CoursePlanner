#include "CoursePlanner.h"
#include "includes/CourseCatalog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CoursePlanner w;
	CourseCatalog* cat = new CourseCatalog();

	// TO-DO: Populate catalog from saved text files

	w.setCatalog(cat);
	w.show();
	return a.exec();
}