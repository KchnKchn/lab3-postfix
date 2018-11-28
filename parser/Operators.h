#pragma once
#include <memory>
#include "Value.h"
#include "Stack.h"

class Plus : public Operator
{
public:
	int GetPriority() { return plus; }
	void Calc(Stack<std::shared_ptr<Operand>> &stack);
};

class Minus : public Operator
{
public:
	int GetPriority() { return minus; }
	void Calc(Stack<std::shared_ptr<Operand>> &stack);
};

class Multiply : public Operator
{
public:
	int GetPriority() { return multiply; }
	void Calc(Stack<std::shared_ptr<Operand>> &stack);
};

class Division : public Operator
{
public:
	int GetPriority() { return division; }
	void Calc(Stack<std::shared_ptr<Operand>> &stack);
};