#include "stdafx.h"
#include "DATEI18NENUM.h"


bool DateValidatorI18N::DateisDateValid(int month, int day, int year)
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
		if (leapYear(year)) // We only care about leap years in February 
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

// leapYear function to determine if the year is a leap year for validation
bool DateValidatorI18N::leapYear(int year)
{
	return(year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}// end leapYear
