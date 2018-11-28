#pragma once
#include <memory>
#include "Value.h"
#include "Queue.h"

class Calculator
{
public:
	std::shared_ptr<Operand> Calculate(Queue<std::shared_ptr<Value>> postfix);
};