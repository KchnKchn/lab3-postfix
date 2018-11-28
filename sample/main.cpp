#include <iostream>
#include <string>
#include <memory>
#include "Value.h"
#include "Queue.h"
#include "Converter.h"
#include "Calculator.h"

int main()
{
	std::string str;
	Converter Convert;
	Calculator Calc;
	std::shared_ptr<Operand> result;
	Queue<std::shared_ptr<Value>> queue;

	std::cout << "Enter mathematical expression : ";
	std::getline(std::cin, str);
	
	queue = Convert.ConvertToQueue(str);
	queue = Convert.ConvertToPostfix(queue);
	result = Calc.Calculate(queue);

	std::cout << "Answer : " << *result.get() << std::endl;
	return 0;
}