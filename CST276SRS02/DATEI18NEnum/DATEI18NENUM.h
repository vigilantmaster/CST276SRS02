#pragma once
#include <string>

class DateValidatorI18Nenum
{
public:
	enum class Format { YMD, DMY, MDY };
private:
	static bool leap_year(int year);
	static bool is_date_valid(int month, int day, int year);
public:
	static bool is_date_valid(std::string date, std::string format);
private:
	static bool isDelim(char c);
	static bool parse_stringstream(std::string inputString, std::string format) ;
};
