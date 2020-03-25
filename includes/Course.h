#pragma once

#include <QString>
#include <vector>
#include <QMetaType>

#include "LocTime.h"
#include "Person.h"
#include "Term.h"

class Section;

class Course
{
public:
	Course();
	Course(const QString& newName, const QString& newSubj,
		int newCredits, int newCrseID);
	Course(const Course& other);

	~Course();

	QString getCourseName() const;
	QString getCourseSubject() const;
	QString getCourseDesc() const;
	int getCourseCredits() const;
	int getCourseID() const;

	void setCrseName(const QString& newName);
	void setCrseDesc(const QString& newDesc);
	void setCrseSubj(const QString& newSubj);
	void setCredits(int newCredits);
	void setCrseID(int newID);

	void addPreReq(int crseID);
	void removePreReq(int crseID);
	void setPreReqs(const std::vector<int> newPreReqs);

	// Returns section ID of new section
	int addSection(const Section& newSec);
	void removeSection(const Section& sec);
	void removeSection(int secID);

	bool operator==(const Course& otherCrse);
	bool operator<(const Course& otherCrse);
	bool operator>(const Course& otherCrse);

private:
	QString courseName, courseDesc, subject;

	qint32 credits, courseID;

	/** Stores course IDs */
	std::vector<int> preReqs;
	std::vector<Section*> sections;
};

Q_DECLARE_METATYPE(Course);