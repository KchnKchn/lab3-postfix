#pragma once
#include <memory>
#include <string>
#include "Value.h"
#include "Queue.h"

class Converter
{
	std::shared_ptr<Operand> CreateOperand(const std::string str, size_t &i);
public:
	Queue<std::shared_ptr<Value>> ConvertToQueue(std::string str);
	Queue<std::shared_ptr<Value>> ConvertToPostfix(Queue<std::shared_ptr<Value>> queue);
};