#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "DATEI18NENUM.h"
#include <ctime>


bool DateValidatorI18Nenum::is_date_valid(const int month, const int day, const int year)
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

bool DateValidatorI18Nenum::is_date_valid(std::string date, std::string format)
{
	return parse_stringstream(date, format);
}

const std::string delims(";,:. \n\t/");
bool DateValidatorI18Nenum::isDelim(char c)
{
	for (size_t i = 0; i < delims.size(); ++i)
		if (delims[i] == c)
			return true;
	return false;
}

bool DateValidatorI18Nenum::parse_stringstream(std::string inputString, std::string format) 
{
	
	std::istringstream ss(inputString);
	std::string token;
	int month{ 0 }, day{ 0 }, year{ 0 };
	std::string sday, smonth, syear;
	Format currentFormat = Format::YMD;
	if (format == "DMY") currentFormat = Format::DMY;
	else if (format == "MDY") currentFormat = Format::MDY;
	switch (currentFormat)
	{
	case Format::YMD:
		
			std::getline(ss, syear, '/');
			std::getline(ss, smonth, '/');
			std::getline(ss, sday, '/');			
		
		break;

	case Format::DMY:
		
			std::getline(ss, sday, '/');
			std::getline(ss, smonth, '/');
			std::getline(ss, syear, '/');		
		
		break;

	case Format::MDY:
		
			std::getline(ss, smonth, '/');
			std::getline(ss, sday, '/');
			std::getline(ss, syear, '/');	
		
		break;
	}
	month = std::stoi(smonth);
	day = std::stoi(sday);
	year = std::stoi(syear);
	return is_date_valid(month, day, year);
}

// leapYear function to determine if the year is a leap year for validation
bool DateValidatorI18Nenum::leap_year(const int year)
{
	return(year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}// end leapYear
