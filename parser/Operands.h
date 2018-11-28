#pragma once
#include <memory>
#include <iostream>
#include "Value.h"

class Number : public Operand
{
	double val;
protected:
	std::ostream &print(std::ostream &stream) const;
public:
	Number(double _val) : val(_val) {}
	double GetVal() { return val; }
	int GetPriority() { return operand; }
	void Calc(Stack<std::shared_ptr<Operand>> &stack);

	Number operator+(const Number &rhs) { return val + rhs.val; }
	Number operator-(const Number &rhs) { return val - rhs.val; }
	Number operator*(const Number &rhs) { return val * rhs.val; }
	Number operator/(const Number &rhs) { return val / rhs.val; }

	std::shared_ptr<Operand> operator+(std::shared_ptr<Operand> rhs);
	std::shared_ptr<Operand> operator-(std::shared_ptr<Operand> rhs);
	std::shared_ptr<Operand> operator/(std::shared_ptr<Operand> rhs);
	std::shared_ptr<Operand> operator*(std::shared_ptr<Operand> rhs);
};