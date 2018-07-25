#pragma once
#include "Strategy.h"
#include "ConcreteStrategyB.h"

class Context
{
public:
	void context_interface() const;
	void set_strategy( Strategy* concrete_strategy);
private:
	Strategy* strategy_{nullptr};
};

