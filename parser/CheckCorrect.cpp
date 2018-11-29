#include <string>
#include "CheckCorrect.h"
#include "Stack.h"

bool CheckBrackets::CheckCorrect(const std::string &str)
{
	Stack<int> bracket;
	int size = str.size();
	try
	{
		for (int i = 0; i < size; i++)
		{
			if (str[i] == '(') bracket.Push(i);
			if (str[i] == ')') bracket.Pop();
		}
	}
	catch (...)
	{
		return false;
	}
	return bracket.IsEmpty();
}