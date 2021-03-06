#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "DATEI18N.h"
#include <ctime>
#include "DateValidatorStrategy.h"

DateValidatorStrategy * DateValidatorI18N::strategy_{ nullptr };
DateValidatorI18N::DateValidatorI18N() 
{
	
}

bool DateValidatorI18N::is_date_valid(std::string date) 
{
	if (nullptr != strategy_)
		return strategy_->is_date_valid(date);
}

void DateValidatorI18N::set_strategy(DateValidatorStrategy* concrete_strategy)
{
	strategy_ = concrete_strategy;
}

