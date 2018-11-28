#pragma once
#include "Value.h"
#include "Stack.h"

class OpeningBracket : public Bracket
{
public:
	OpeningBracket() : Bracket("Open") {}
	int GetPriority() { return bracket; }
	void Calc(Stack<std::shared_ptr<Operand>> &stack) { stack; throw - 1; }
};

class ClosingBracket : public Bracket
{
public:
	ClosingBracket() : Bracket("Close") {}
	int GetPriority() { return bracket; }
	void Calc(Stack<std::shared_ptr<Operand>> &stack) { stack; throw - 1; }
};