#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupport_c.h"
#include "mock_module_a.h"

TEST_GROUP(test_mocking)
{
    void setup()
    {
        mock().expectOneCall("init");
        mock().expectOneCall("reset");
        init();
    }

    void teardown()
    {
        reset();
        mock().checkExpectations();
        mock().clear();
    }
};


TEST(test_mocking, assertion_int32_equal)
{ 
	int32_t exp = 128;
    mock().expectNCalls(2, "multiply_by_two").withDoubleParameter("value", exp);
    mock().expectOneCall("divide_by_half").withDoubleParameter("value", (int32_t)multiply_by_two(exp));
    mock().expectNCalls(2, "power_of_two").withDoubleParameter("value", exp);
    mock().expectOneCall("square_root").withDoubleParameter("value", (int32_t)power_of_two(exp));

	CHECK_EQUAL(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
	CHECK_EQUAL(exp, (int32_t)square_root((int32_t)power_of_two(exp)));
}


TEST(test_mocking, assertion_uint32_equal)
{
    uint32_t exp = 128;
    mock().expectNCalls(2, "multiply_by_two").withDoubleParameter("value", exp);
    mock().expectOneCall("divide_by_half").withDoubleParameter("value", (uint32_t)multiply_by_two(exp));
    mock().expectNCalls(2, "power_of_two").withDoubleParameter("value", exp);
    mock().expectOneCall("square_root").withDoubleParameter("value", (uint32_t)power_of_two(exp));

    CHECK_EQUAL(exp, (uint32_t)divide_by_half((uint32_t)multiply_by_two(exp)));
    CHECK_EQUAL(exp, (uint32_t)square_root((uint32_t)power_of_two(exp)));
}

TEST(test_mocking, assertion_hex32_equal)
{
    int32_t exp = 0x00000800u;
    mock().expectNCalls(2, "multiply_by_two").withDoubleParameter("value", exp);
    mock().expectOneCall("divide_by_half").withDoubleParameter("value", (int32_t)multiply_by_two(exp));
    mock().expectNCalls(2, "power_of_two").withDoubleParameter("value", exp);
    mock().expectOneCall("square_root").withDoubleParameter("value", (int32_t)power_of_two(exp));

    CHECK_EQUAL(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
    CHECK_EQUAL(exp, (int32_t)square_root((int32_t)power_of_two(exp)));
}

TEST(test_mocking, assertion_float_equal)
{
    float_t exp = 128.000f;
    mock().expectNCalls(2, "multiply_by_two").withDoubleParameter("value", exp);
    mock().expectOneCall("divide_by_half").withDoubleParameter("value", (float_t)multiply_by_two(exp));
    mock().expectNCalls(2, "power_of_two").withDoubleParameter("value", exp);
    mock().expectOneCall("square_root").withDoubleParameter("value", (float_t)power_of_two(exp));

    LONGS_EQUAL(exp, (float_t)divide_by_half((float_t)multiply_by_two(exp)));
    LONGS_EQUAL(exp, (float_t)square_root((float_t)power_of_two(exp)));
}

TEST(test_mocking, assertion_double_equal)
{
    double_t exp = 128.000;
    mock().expectNCalls(2, "multiply_by_two").withDoubleParameter("value", exp);
    mock().expectOneCall("divide_by_half").withDoubleParameter("value", (double_t)multiply_by_two(exp));
    mock().expectNCalls(2, "power_of_two").withDoubleParameter("value", exp);
    mock().expectOneCall("square_root").withDoubleParameter("value", (double_t)power_of_two(exp));

    LONGS_EQUAL(exp, (double_t)divide_by_half((double_t)multiply_by_two(exp)), 0.01);
    LONGS_EQUAL(exp, (double_t)square_root((double_t)power_of_two(exp)), 0.01);
}