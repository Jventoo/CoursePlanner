#pragma once

#include <qglobal.h>

class CourseDelegatePrivate
{
	CourseDelegatePrivate();

	inline QRect timestampBox(const QStyleOptionViewItem& option,
		const QModelIndex& index) const;
	inline qreal timestampFontPointSize(const QFont& f) const;
	inline QRect messageBox(const QStyleOptionViewItem& option) const;

	QMargins margins;
	int spacingHorizontal;
	int spacingVertical;

	friend class CourseDelegate;
};