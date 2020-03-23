#include "includes/LocTime.h"

LocTime::LocTime()
{
	time.hour = 0;
	time.minutes = 0;

	milTime = true;
	pm = false;
}

void LocTime::setLocation(const QString& newLoc)
{
	location = newLoc;
}

void LocTime::setDays(const std::vector<Day> newDays)
{
	days = newDays;
}

void LocTime::setTime(const Time& newTime)
{
	auto newHr = newTime.hour;
	if (newHr < 0 || newHr > 23)
		throw newHr;
	else
		time.hour = newHr;

	auto newMin = newTime.minutes;
	if (newMin < 0 || newMin > 59)
		throw newMin;
	else
		time.minutes = newMin;

	milTime = true;
	pm = false;
}

void LocTime::setLocDetails(const QString& newLoc,
	const std::vector<Day> newDays, const Time& newTime)
{
	setLocation(newLoc);
	setDays(newDays);
	setTime(newTime);
}

void LocTime::translateTo24(Time& newTime)
{
	if (pm && newTime.hour != 12)
		newTime.hour += 12;
	else if (!pm && newTime.hour == 12)
		newTime.hour -= 12;

	pm = false;
	milTime = true;
}

void LocTime::translateTo12(Time& newTime)
{
	if (newTime.hour > 11)
		pm = true;
	else
		pm = false;

	if (newTime.hour == 0)
		newTime.hour += 12;
	else if (newTime.hour > 12)
		newTime.hour -= 12;

	milTime = false;
}

std::stringstream LocTime::formatTime(const Time& newTime)
{
	std::stringstream ss;

	if (milTime)
		translateTo12(time);

	ss << newTime.hour << ":" << newTime.minutes;

	if (pm)
		ss << " PM";
	else
		ss << " AM";

	return ss;
}