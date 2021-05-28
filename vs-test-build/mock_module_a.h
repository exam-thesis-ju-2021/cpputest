#ifndef MOCK_MODULE_A
#define MOCK_MODULE_A

#include <CppUTestExt/MockSupport.h>
#include "library/module_a.h"

void init()
{
    mock().actualCall("init");
}

void reset()
{
    mock().actualCall("reset");
}

double divide_by_half(double value)
{
	mock().actualCall("divide_by_half").withParameter("value", value);
	return value / 2;
}

double multiply_by_two(double value)
{
	mock().actualCall("multiply_by_two").withParameter("value", value);
	return value * 2;
}

double power_of_two(double value)
{
	mock().actualCall("power_of_two").withParameter("value", value);
	return pow(value, 2);
}

double square_root(double value)
{
	mock().actualCall("square_root").withParameter("value", value);
	return sqrt(value);
}

#endif