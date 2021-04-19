#pragma once

#include <stdexcept>

class DivideByZeroException : public std::runtime_error
{
public:
	DivideByZeroException()
		: std::runtime_error("attempted to divide by zero") {}
};

class NumberTooLargeException : public std::runtime_error
{
public:
	NumberTooLargeException()
		: std::runtime_error{ "number outside acceptible range" }{}
};