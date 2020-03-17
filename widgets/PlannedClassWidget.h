#pragma once

#include <QGroupBox>
#include "ui_PlannedClassWidget.h"

class PlannedClassWidget : public QGroupBox, public Ui::PlannedClassWidget
{
	Q_OBJECT

public:
	PlannedClassWidget(QWidget *parent = Q_NULLPTR);
	~PlannedClassWidget();
};
