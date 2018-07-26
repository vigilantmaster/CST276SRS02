#pragma once
#include <string>
#include "DateValidatorStrategy.h"


//strategy pattern context
class DateValidatorI18N
{
public:
	DateValidatorI18N();
	static bool is_date_valid(std::string date);
	static void set_strategy(DateValidatorStrategy* concrete_strategy);
private:
	static DateValidatorStrategy * strategy_;
};
