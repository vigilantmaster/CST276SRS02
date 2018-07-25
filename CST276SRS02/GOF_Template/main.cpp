// GOF_Template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AbstractClass.h"
#include "ConcreteClass.h"


int main()
{
	ConcreteClass concrete_class;
	AbstractClass& abstract_class{ concrete_class };
	abstract_class.TemplateMethod();
    return 0;
}

