#include <memory>
#include <string>
#include "Value.h"
#include "Brackets.h"
#include "Operands.h"
#include "Operators.h"
#include "Queue.h"
#include "Converter.h"

std::shared_ptr<Operand> Converter::CreateOperand(const std::string str, size_t &i)
{
	std::string result = "";
	while (((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
	{
		result += str[i];
		i++;
	}
	i--;
	return std::make_shared<Number>(std::stoi(result));
}

Queue<std::shared_ptr<Value>> Converter::ConvertToQueue(std::string str)
{
	Queue<std::shared_ptr<Value>> result;
	size_t StringSize = str.size();
	for (size_t i = 0; i < StringSize; i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			result.Push(CreateOperand(str, i));
			continue;
		}
		switch (str[i])
		{
		case '+':
		{
			result.Push(std::make_shared<Plus>());
			break;
		}
		case '-':
		{
			result.Push(std::make_shared<Minus>());
			break;
		}
		case '*':
		{
			result.Push(std::make_shared<Multiply>());
			break;
		}
		case '/':
		{
			result.Push(std::make_shared<Division>());
			break;
		}
		case '(':
		{
			result.Push(std::make_shared<OpeningBracket>());
			break;
		}
		case ')':
		{
			result.Push(std::make_shared<ClosingBracket>());
			break;
		}
		default:
		{
			throw - 1;
			break;
		}
		}
	}
	return result;
}

Queue<std::shared_ptr<Value>> Converter::ConvertToPostfix(Queue<std::shared_ptr<Value>> queue)
{
	Queue<std::shared_ptr<Value>> postfix;
	Stack<std::shared_ptr<Value>> operators;
	std::shared_ptr<Value> val;
	while (!queue.IsEmpty())
	{
		val = queue.Pop();
		if (val->GetPriority() < 0)
		{
			postfix.Push(val);
			continue;
		}
		if (val->GetPriority() > 0)
		{
			if (!operators.IsEmpty())
			{
				std::shared_ptr<Value> predop = operators.Pop();
				if (predop->GetPriority() < val->GetPriority())
				{
					operators.Push(predop);
					operators.Push(val);
					continue;
				}
				else
				{
					postfix.Push(predop);
					operators.Push(val);
					continue;
				}
			}
			else
			{
				operators.Push(val);
				continue;
			}
		}
		if(val->GetPriority() == 0)
		{
			std::string bracket = (dynamic_cast<Bracket*>(val.get()))->GetName();
			if (bracket == "Open")
			{
				operators.Push(val);
				continue;
			}
			else
			{
				std::shared_ptr<Value> predop = operators.Pop();
				while (predop->GetPriority() != 0)
				{
					postfix.Push(predop);
					predop = operators.Pop();
				}
				continue;
			}
		}
	}
	while (!operators.IsEmpty())
	{
		std::shared_ptr<Value> predop;
		predop = operators.Pop();
		postfix.Push(predop);
	}
	return postfix;
}