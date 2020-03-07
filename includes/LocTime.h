#pragma once

#include <vector>
#include <string>
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
	
	void setLocation(const std::string& newLoc);
	void setDays(const std::vector<Day> newDays);

	/** Only set in 24 hour format! */
	void setTime(const Time& newTime);
	void setLocDetails(const std::string& location,
		const std::vector<Day> days, const Time& time);

	void translateTo24(Time& time);
	void translateTo12(Time& time);

	std::stringstream formatTime(const Time& time);

private:
	std::string location;
	std::vector<Day> days;
	
	Time time;
	bool milTime;
	bool pm;
};