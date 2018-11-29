#pragma once
#include <string>

class BaseCheck
{
public:
	virtual bool CheckCorrect(const std::string &str) = 0;
};

class CheckBrackets
{
public:
	bool CheckCorrect(const std::string &str);
};