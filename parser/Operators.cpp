#include <memory>
#include "Value.h"
#include "Stack.h"
#include "Operators.h"
#include "Operands.h"

void Plus::Calc(Stack<std::shared_ptr<Operand>> &stack)
{
	std::shared_ptr<Operand> second = stack.Pop();
	std::shared_ptr<Operand> first = stack.Pop();
	stack.Push(first->operator+(second));
}

void Minus::Calc(Stack<std::shared_ptr<Operand>> &stack)
{
	std::shared_ptr<Operand> second = stack.Pop();
	std::shared_ptr<Operand> first = stack.Pop();
	stack.Push(first->operator-(second));
}

void Division::Calc(Stack<std::shared_ptr<Operand>> &stack)
{
	std::shared_ptr<Operand> second = stack.Pop();
	std::shared_ptr<Operand> first = stack.Pop();
	stack.Push(first->operator/(second));
}

void Multiply::Calc(Stack<std::shared_ptr<Operand>> &stack)
{
	std::shared_ptr<Operand> second = stack.Pop();
	std::shared_ptr<Operand> first = stack.Pop();
	stack.Push(first->operator*(second));
}