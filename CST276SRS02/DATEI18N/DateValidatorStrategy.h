#pragma once
#include <string>


class DateValidatorStrategy
{
public:
	DateValidatorStrategy() = default;
	DateValidatorStrategy(const DateValidatorStrategy& other) = delete;
	DateValidatorStrategy& operator=(const DateValidatorStrategy& other) = delete;
	DateValidatorStrategy& operator=(DateValidatorStrategy&& other) noexcept = delete;
	DateValidatorStrategy(DateValidatorStrategy&& other) noexcept = delete;
	virtual ~DateValidatorStrategy() = default;
	//GOF Strategy Pattern : this is an interface
	virtual bool is_date_valid(std::string date) = 0;
};
