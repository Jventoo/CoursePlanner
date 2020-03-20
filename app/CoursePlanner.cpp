#include "CoursePlanner.h"
#include "PlannedClassWidget.h"
//#include "includes/Course.h"

CoursePlanner::CoursePlanner(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	catalogObj = nullptr;
}

CoursePlanner::~CoursePlanner()
{
	delete catalogObj;
	catalogObj = nullptr;
}

void CoursePlanner::setCatalog(CourseCatalog* newPtr)
{
	catalogObj = newPtr;

	// APPROACH 1

	//for (const auto& e : catalogObj->getCatalog())
	//{
	//	// Create course widget from element e
	//	// auto temp = new PlannedClassWidget(e);

	//	// Populate the following with each new widget
	//	QAbstractListModel* model;
	//	ui.coursesList->setModel(model);
	//}

	
	// APPROACH 2
	
	// loop as before
	// inner loop -> create dyn widget, add to scrollbox
	// (slower, more expensive although may be practical on small scale)
}