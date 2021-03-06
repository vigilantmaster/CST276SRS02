// GOF_Strategy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Context.h"
#include "ConcreteStrategyB.h"
#include "ConcreteStrategyA.h"
#include "ConcreteStrategyC.h"


int main()
{
	//using the GOF strategy pattern
	Context context;
	ConcreteStrategyA concrete_strategy_a;
	ConcreteStrategyB concrete_strategy_b;
	ConcreteStrategyC concrete_strategy_c;

	context.set_strategy(&concrete_strategy_a);
	context.context_interface();
	context.set_strategy(&concrete_strategy_b);
	context.context_interface();
	context.set_strategy(&concrete_strategy_c);
	context.context_interface();
    return 0;
}

