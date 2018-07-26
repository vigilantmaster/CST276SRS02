#include "stdafx.h"
#include "YMD_Strategy.h"
#include <sstream>

bool YMD_Strategy::is_date_valid(const int month, const int day, const int year)
{
	//source of this code https://stackoverflow.com/questions/13577555/c-validating-date-without-using-class
	bool validation = true;
	if (!(year >= 1600 && year <= 2100)) // if not within range valid = false
		validation = false;

	if (day < 1)
		validation = false;

	switch (month)
	{
	case 2:
		if (leap_year(year)) // We only care about leap years in February 
			if (day > 29)
				validation = false;
			else
				if (day > 28)
					validation = false;
		break;
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (day > 31)
			validation = false;
		break;
	case 4: case 6: case 9: case 11:
		if (day > 30)
			validation = false;
		break;
	default: // the month is not between 1 and 12
		validation = false;
		break;
	}
	return validation;
}

bool YMD_Strategy::is_date_valid(std::string date)
{
	return parse_stringstream(date);
}

bool YMD_Strategy::parse_stringstream(std::string inputString)
{

	std::istringstream ss(inputString);
	std::string token;
	int month{ 0 }, day{ 0 }, year{ 0 };
	std::string sday, smonth, syear;

	std::getline(ss, syear, '/');
	std::getline(ss, smonth, '/');
	std::getline(ss, sday, '/');	

	month = std::stoi(smonth);
	day = std::stoi(sday);
	year = std::stoi(syear);
	return is_date_valid(month, day, year);
}
// leapYear function to determine if the year is a leap year for validation
bool YMD_Strategy::leap_year(const int year)
{
	return(year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}// end leapYear