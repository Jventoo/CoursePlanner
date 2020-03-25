#include "CourseDelegate.h"
#include "CourseDelegate_p.h"
#include "includes/Course.h"

#include <QPainter>

CourseDelegate::CourseDelegate(QObject* parent) :
	QStyledItemDelegate(parent),
	m_ptr(new CourseDelegatePrivate)
{

}

CourseDelegate::~CourseDelegate()
{
	delete m_ptr;
}

QMargins CourseDelegate::contentsMargins() const
{
	return m_ptr->margins;
}

void CourseDelegate::setContentsMargins(int left, int top, int right, int bottom)
{
	m_ptr->margins = QMargins(left, top, right, bottom);
}

int CourseDelegate::horizontalSpacing() const
{
	return m_ptr->spacingHorizontal;
}

void CourseDelegate::setHorizontalSpacing(int spacing)
{
	m_ptr->spacingHorizontal = spacing;
}

int CourseDelegate::verticalSpacing() const
{
	return m_ptr->spacingVertical;
}

void CourseDelegate::setVerticalSpacing(int spacing)
{
	m_ptr->spacingVertical = spacing;
}

void CourseDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QStyleOptionViewItem opt(option);
	initStyleOption(&opt, index);

	const QPalette& palette(opt.palette);
	const QRect& rect(opt.rect);
	const QRect& contentRect(rect.adjusted(m_ptr->margins.left(),
		m_ptr->margins.top(),
		-m_ptr->margins.right(),
		-m_ptr->margins.bottom()));
	const bool lastIndex = (index.model()->rowCount() - 1) == index.row();
	const bool hasIcon = !opt.icon.isNull();
	const int bottomEdge = rect.bottom();
	QFont f(opt.font);

	f.setPointSize(m_ptr->timestampFontPointSize(opt.font));

	painter->save();
	painter->setClipping(true);
	painter->setClipRect(rect);
	painter->setFont(opt.font);

	// Draw background
	painter->fillRect(rect, opt.state & QStyle::State_Selected ?
		palette.highlight().color() :
		palette.light().color());

	// Draw bottom line
	painter->setPen(lastIndex ? palette.dark().color()
		: palette.mid().color());
	painter->drawLine(lastIndex ? rect.left() : m_ptr->margins.left(),
		bottomEdge, rect.right(), bottomEdge);

	// Draw timestamp
	QRect timeStampRect(m_ptr->timestampBox(opt, index));

	timeStampRect.moveTo(m_ptr->margins.left()
		+ m_ptr->spacingHorizontal, contentRect.top());

	painter->setFont(f);
	painter->setPen(palette.text().color());

	Course tempCourse = index.data(Qt::UserRole).value<Course>();
	QString coursePref = tempCourse.getCourseSubject();

	painter->drawText(timeStampRect, Qt::TextSingleLine,
		tr("BLAH"));

	// Draw message text
	QRect messageRect(m_ptr->messageBox(opt));

	messageRect.moveTo(timeStampRect.left(), timeStampRect.bottom()
		+ m_ptr->spacingVertical);

	painter->setFont(opt.font);
	painter->setPen(palette.windowText().color());
	painter->drawText(messageRect, Qt::TextSingleLine, opt.text);

	painter->restore();
}

QSize CourseDelegate::sizeHint(const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QStyleOptionViewItem opt(option);
	initStyleOption(&opt, index);

	int textHeight = m_ptr->timestampBox(opt, index).height()
		+ m_ptr->spacingVertical + m_ptr->messageBox(opt).height();

	return QSize(opt.rect.width(), m_ptr->margins.top() + textHeight
		+ m_ptr->margins.bottom());
}


CourseDelegatePrivate::CourseDelegatePrivate() :
	margins(0, 0, 0, 0),
	spacingHorizontal(0),
	spacingVertical(0)
{

}

QRect CourseDelegatePrivate::timestampBox(const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QFont f(option.font);

	f.setPointSizeF(timestampFontPointSize(option.font));

	return QFontMetrics(f).boundingRect(index.data(Qt::UserRole).toString())
		.adjusted(0, 0, 1, 1);
}

qreal CourseDelegatePrivate::timestampFontPointSize(const QFont& f) const
{
	return 0.85 * f.pointSize();
}

QRect CourseDelegatePrivate::messageBox(const QStyleOptionViewItem& option) const
{
	return option.fontMetrics.boundingRect(option.text).adjusted(0, 0, 1, 1);
}