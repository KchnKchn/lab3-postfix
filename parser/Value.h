#pragma once
#include <memory>
#include <iostream>
#include "Stack.h"

class Operand;

class Value
{
protected:
	const enum Priority { operand = -1, bracket = 0, plus = 1, minus = 1, multiply = 2, division = 2, uplus = 3, uminus = 3 };
public:
	virtual int GetPriority() = 0;
	virtual void Calc(Stack<std::shared_ptr<Operand>> &stack) = 0;
	virtual ~Value() = 0 {}
};

class Bracket : public Value
{
public:
	virtual bool isopen() const = 0;
};

class Operand : public Value
{
protected:
	virtual std::ostream &print(std::ostream &stream) const = 0;
public:
	virtual std::shared_ptr<Operand> operator+(std::shared_ptr<Operand> rhs) = 0;
	virtual std::shared_ptr<Operand> operator-(std::shared_ptr<Operand> rhs) = 0;
	virtual std::shared_ptr<Operand> operator/(std::shared_ptr<Operand> rhs) = 0;
	virtual std::shared_ptr<Operand> operator*(std::shared_ptr<Operand> rhs) = 0;
	friend std::ostream &operator<<(std::ostream &stream, const Operand &rhs) { return rhs.print(stream); }
};

class Operator : public Value
{
};