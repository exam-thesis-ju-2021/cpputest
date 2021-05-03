#include "CppUTestExt/MockSupport.h"

extern "C"
{
#include <stdio.h>
#include "square_root.h"
}


int SquareRoot_sqrt()
{
    return mock().actualCall(__func__).returnIntValue();
}