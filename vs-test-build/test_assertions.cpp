/*#include "CppUTest/TestHarness.h"

extern "C"
{
#include "library/hardware.h"
#include "library/peripherals.h"
#include "library/peripheral.h"
#include "library/module_a.h"
#include "library/peripherals/divide_by_half.h"
#include "library/peripherals/multiply_by_two.h"
#include "library/peripherals/power_of_two.h"
#include "library/peripherals/square_root.h"
}

TEST_GROUP(Assert_test)
{
    void setup()
    {
        init();
    }

    void teardown()
    {
        reset();
    }
};

TEST(Assert_test, Check)
{
    CHECK(divide_by_half(128) == multiply_by_two(32));
}

TEST(Assert_test, Check_False)
{
    CHECK_FALSE(divide_by_half(128) != multiply_by_two(32));
}

TEST(Assert_test, Check_equal_uint)
{
    uint32_t exp= 128;
    CHECK_EQUAL(exp, (uint32_t)divide_by_half((uint32_t)multiply_by_two(exp)));
}

TEST(Assert_test, Check_equal_int16)
{
    int16_t exp = 128;
    CHECK_EQUAL(exp, (int16_t)divide_by_half((int16_t)multiply_by_two(exp)));
}

TEST(Assert_test, Check_equal_HEX)
{
    int exp = 0x00000800u;
    CHECK_EQUAL(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
}

TEST(Assert_test, Check_equal_double)
{
    double exp = 128;
    CHECK_EQUAL(exp, divide_by_half(multiply_by_two(exp)));
}

TEST(Assert_test, Check_equal_char)
{
    char exp = 'A';
    char act = 'A';
    CHECK_EQUAL(exp, act);
}

TEST(Assert_test, Check_equal_intArray)
{
    int exp[] = { 1,2,3,4,5 };
    int act[] = { 1,2,3,4,6 };
    CHECK_EQUAL(exp, act);

    // Failed test, cant check arrays
}

TEST(Assert_test, Check_equal_charArray)
{
    char exp[] = { 'a','b','c','d','e' };
    char act[] = { 'a','b','c','d','e' };
    CHECK_EQUAL(exp, act);

    // Failed test, cant check arrays
}

TEST(Assert_test, Strcmp_equal)
{
    char *exp = "Hello World";
    char *act = "Hello World";
    STRCMP_EQUAL(exp, act);
}

TEST(Assert_test, Bytes_equal)
{
    char exp = 'A';
    char act = 'A';
    BYTES_EQUAL(exp, act);
}

TEST(Assert_test, Pointers_equal)
{
    int x = 1;
    int* exp = &x;
    int* act = &x;
    POINTERS_EQUAL(exp, act);
}

TEST(Assert_test, Memcmp_equal)
{   
    int* exp = (int*)malloc(sizeof(int));
    int* act = (int*)malloc(sizeof(int));

    *exp = 5;
    *act = 5;

    printf("Address stored in exp variable: %x\n", exp);
    printf("Address stored in act variable: %x\n", act);

    MEMCMP_EQUAL(exp, act, sizeof(int));
    free(act);
    free(exp);
}
*/
