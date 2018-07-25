#pragma once
#include "AbstractClass.h"
class ConcreteClass :
	public AbstractClass
{
public:
	ConcreteClass();
	~ConcreteClass();
private:
	void PrimitiveOperation1() override;
	void PrimitiveOperation2() override;
};

