#pragma once
#include "DateValidatorStrategy.h"

// this is the strategy that I added to DATE18NENUM

class YDM_Strategy : public DateValidatorStrategy
{
public:

	bool is_date_valid(int month, int day, int year);
	bool is_date_valid(std::string date) override;
	bool parse_stringstream(std::string inputString);
	static bool leap_year(int year);
};