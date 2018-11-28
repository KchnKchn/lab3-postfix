#pragma once
#include "Value.h"
#include "Stack.h"

class OpeningBracket : public Bracket
{
public:
	bool isopen() const { return true; }
	int GetPriority() { return bracket; }
	void Calc(Stack<std::shared_ptr<Operand>> &stack) { stack; throw - 1; }
};

class ClosingBracket : public Bracket
{
public:
	bool isopen() const { return false; }
	int GetPriority() { return bracket; }
	void Calc(Stack<std::shared_ptr<Operand>> &stack) { stack; throw - 1; }
};