#pragma once
class DateValidatorI18N
{
public:
	enum class Format { YMD, DMY, MDY };

	static bool leapYear(int year);
	static bool DateisDateValid(int month, int day, int year);
};