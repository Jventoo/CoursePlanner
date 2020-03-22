#include "CoursePlanner.h"
#include "includes/CourseCatalog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CoursePlanner w;

	// TO-DO: Populate catalog from saved text files

	w.show();
	return a.exec();
}