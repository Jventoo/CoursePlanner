#pragma once

#include <vector>
#include <QString>
#include <sstream>

class LocTime
{
public:

	/** 24-hour format */
	struct Time
	{
		int minutes;
		int hour;
	};

	enum class Day {
		Sunday, Monday, Tuesday,
		Wednesday, Thursday, Friday, Saturday
	};

	LocTime();
	
	void setLocation(const QString& newLoc);
	void setDays(const std::vector<Day> newDays);

	/** Only set in 24 hour format! */
	void setTime(const Time& newTime);
	void setLocDetails(const QString& location,
		const std::vector<Day> days, const Time& time);

	void translateTo24(Time& time);
	void translateTo12(Time& time);

	std::stringstream formatTime(const Time& time);

private:
	QString location;
	std::vector<Day> days;
	
	Time time;
	bool milTime;
	bool pm;
};