#include <memory>
#include <iostream>
#include "Value.h"
#include "Operands.h"
#include "Stack.h"

std::ostream &Number::print(std::ostream &stream) const
{
	stream << val;
	return stream;
}

void Number::Calc(Stack<std::shared_ptr<Operand>> &stack)
{
	stack.Push(std::make_shared<Number>(*this));
}

std::shared_ptr<Operand> Number::operator+(std::shared_ptr<Operand> rhs)
{
	Number op = *dynamic_cast<Number*>(rhs.get());
	return std::make_shared<Number>(*this + op);
}
std::shared_ptr<Operand> Number::operator-(std::shared_ptr<Operand> rhs)
{
	Number op = *dynamic_cast<Number*>(rhs.get());
	return std::make_shared<Number>(*this - op);
}
std::shared_ptr<Operand> Number::operator/(std::shared_ptr<Operand> rhs)
{
	Number op = *dynamic_cast<Number*>(rhs.get());
	return std::make_shared<Number>(*this / op);
}
std::shared_ptr<Operand> Number::operator*(std::shared_ptr<Operand> rhs)
{
	Number op = *dynamic_cast<Number*>(rhs.get());
	return std::make_shared<Number>(*this * op);
}