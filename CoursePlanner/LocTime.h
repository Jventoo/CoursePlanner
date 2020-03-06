#pragma once

#include <vector>
#include <string>
#include <sstream>

struct Time
{
	int minutes;
	int hour;
};

class LocTime
{
public:
	enum class Day {
		Sunday, Monday, Tuesday,
		Wednesday, Thursday, Friday, Saturday
	};

	LocTime();
	
	void setLocation(const std::string& location);
	void setDays(const std::vector<Day> days);

	/** Only set in 24 hour format! */
	void setTime(const Time& time);
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