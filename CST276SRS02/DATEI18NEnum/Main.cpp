// DATEI18NEnum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DATEI18NENUM.h"
#include <cassert>


int main()
{
	DateValidatorI18Nenum date_validator;
	auto valid{ date_validator.is_date_valid("12/24/2017", "MDY") };
	assert(valid);
	valid = date_validator.is_date_valid("2010/02/22", "YMD");
	assert(valid);
	return 0;
}

