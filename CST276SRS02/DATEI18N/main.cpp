// DATEI18N.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DATEI18N.h"
#include "DMY_Strategy.h"
#include "MDY_Strategy.h"
#include <cassert>
#include "YDM_Strategy.h"
#include "YMD_Strategy.h"


int main()
{
	//make a context
	DateValidatorI18N date_validator;
	//set Day Month Year to context
	DMY_Strategy DMY_Strategy;
	date_validator.set_strategy(&DMY_Strategy);
	//execute DMY strategy in context
	assert(date_validator.is_date_valid("23/10/1950"));

	//set Month Day Year strategy
	MDY_Strategy MDY_Strategy;
	date_validator.set_strategy(&MDY_Strategy);
	//execute MDY strategy
	assert(date_validator.is_date_valid("2/28/1930"));

	//set Year Day Month strategy
	YDM_Strategy YDM_Strategy;
	date_validator.set_strategy(&YDM_Strategy);
	//execute YDM strategy
	assert(date_validator.is_date_valid("2010/04/1"));

	//set Year Month Day strategy
	YMD_Strategy ymd_Strategy;
	date_validator.set_strategy(&ymd_Strategy);
	//execute MDY strategy
	assert(date_validator.is_date_valid("2000/8/05"));
	assert(date_validator.is_date_valid("2000/18/05") == false);

    return 0;
}

