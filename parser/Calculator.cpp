#include <memory>
#include "Value.h"
#include "Queue.h"
#include "Stack.h"
#include "Calculator.h"

std::shared_ptr<Operand> Calculator::Calculate(Queue<std::shared_ptr<Value>> postfix)
{
	Stack<std::shared_ptr<Operand>> operands;
	std::shared_ptr<Value> currval;
	std::shared_ptr<Operand> result;
	while (!postfix.IsEmpty())
	{
		currval = postfix.Pop();
		currval->Calc(operands);
	}
	result = operands.Pop();
	return result;
}