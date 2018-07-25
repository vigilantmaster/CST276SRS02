#include "stdafx.h"
#include "Context.h"


void Context::context_interface() const
{
	if (strategy_ != nullptr)
	{
		strategy_->AlgorithmInterface();
	}
}

void Context::set_strategy( Strategy* concrete_strategy)
{
	strategy_ = concrete_strategy;
}
