#include "CppUTest/TestHarness.h"

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
#include <math.h>
#include <stdlib.h>
}

TEST_GROUP(test_assertions)
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

TEST(test_assertions, boolean_true)
{
    bool act = (NULL == NULL);
    CHECK(act);
}

TEST(test_assertions, boolean_false)
{
    bool act = (NULL != NULL);
    CHECK_FALSE(act);
}

TEST(test_assertions, null)
{
    int32_t* act = NULL;
    CHECK_EQUAL(NULL, act);
}

TEST(test_assertions, not_null)
{
    int32_t act = 128;
    CHECK_FALSE(act == NULL);
}

TEST(test_assertions, int32_equal)
{
    int32_t exp = 128;
    CHECK_EQUAL(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
    CHECK_EQUAL(exp, (int32_t)square_root((int32_t)power_of_two(exp)));
}

TEST(test_assertions, uint32_equal)
{
    uint32_t exp = 128;
    CHECK_EQUAL(exp, (uint32_t)divide_by_half((uint32_t)multiply_by_two(exp)));
    CHECK_EQUAL(exp, (uint32_t)square_root((uint32_t)power_of_two(exp)));
}

TEST(test_assertions, hex32_equal)
{
    int32_t exp = 0x00000800u;
    CHECK_EQUAL(exp, (int32_t)divide_by_half((int32_t)multiply_by_two(exp)));
    CHECK_EQUAL(exp, (int32_t)square_root((int32_t)power_of_two(exp)));
}

TEST(test_assertions, float_equal)
{
    float_t exp = 128.000f;
    LONGS_EQUAL(exp, (float_t)divide_by_half((float_t)multiply_by_two(exp)));
    LONGS_EQUAL(exp, (float_t)square_root((float_t)power_of_two(exp)));
}

TEST(test_assertions, double_equal)
{
    double_t exp = 128.000;
    LONGS_EQUAL(exp, (double_t)divide_by_half((double_t)multiply_by_two(exp)), 0.01);
    LONGS_EQUAL(exp, (double_t)square_root((double_t)power_of_two(exp)), 0.01);
}

TEST(test_assertions, float_infinity)
{
    float_t act = INFINITY;
    CHECK_EQUAL(INFINITY, act);
}

TEST(test_assertions, double_infinity)
{
    double_t act = INFINITY;
    CHECK_EQUAL(INFINITY, act);
}

TEST(test_assertions, float_not_infinity)
{
    float_t act = 0.0f;
    CHECK_FALSE(isinf(INFINITY) == isinf(act));
}

TEST(test_assertions, double_not_infinity)
{
    double_t act = 0.0;
    CHECK_FALSE(isinf(INFINITY) == isinf(act));
}

TEST(test_assertions, float_negative_infinity)
{
    float_t act = -INFINITY;
    CHECK_EQUAL(-INFINITY, act);
}

TEST(test_assertions, double_negative_infinity)
{
    double_t act = -INFINITY;
    CHECK_EQUAL(-INFINITY, act);
}

TEST(test_assertions, float_not_negative_infinity)
{
    float_t act = -0.0f;
    CHECK_FALSE(isinf(-INFINITY) == isinf(act));
}

TEST(test_assertions, double_not_negative_infinity)
{
    double_t act = -0.0;
    CHECK_FALSE(isinf(-INFINITY) == isinf(act));
}

TEST(test_assertions, float_nan)
{
    float_t divider = 0.0f;
    float_t act = 0.0f / divider;
    CHECK(isnan(act));
}

TEST(test_assertions, double_nan)
{
    double_t divider = 0.0;
    double_t act = 0.0 / divider;
    CHECK(isnan(act));
}

TEST(test_assertions, float_not_nan)
{
    float_t act = 0.0f;
    CHECK(!isnan(act));
}

TEST(test_assertions, double_not_nan)
{
    double_t act = 0.0;
    CHECK(!isnan(act));
}

TEST(test_assertions, float_determinate)
{
    float_t act = 0.0f;
    CHECK(!isnan(act) && isfinite(act));
}

TEST(test_assertions, double_determinate)
{
    double_t act = 0.0;
    CHECK(!isnan(act) && isfinite(act));
}

TEST(test_assertions, float_not_determinate)
{
    float_t act = INFINITY;
    CHECK(isnan(act) || !isfinite(act));
}

TEST(test_assertions, double_not_determinate)
{
    double_t act = INFINITY;
    CHECK(isnan(act) || !isfinite(act));
}

TEST(test_assertions, masked_bits_match)
{
    int32_t mask = 0b00001111;
    int32_t exp = 0b10101111;
    int32_t act = 0b01011111;

    BITS_EQUAL(exp, act, mask);
}

TEST(test_assertions, masked_bits_high)
{
    int32_t mask = 0b00001111;
    int32_t exp = 0b10101111;
    int32_t act = 0b01011111;

    BITS_EQUAL(exp, act, mask);
}

TEST(test_assertions, masked_bits_low)
{
    int32_t mask = 0b00001111;
    int32_t exp = 0b10100000;
    int32_t act = 0b10100000;

    BITS_EQUAL(exp, act, mask);
}

TEST(test_assertions, masked_bit_high)
{
    int32_t mask = 0b10000000;

    int32_t bit = 7;
    int32_t exp = 0b00000000;
    exp ^= 1UL << bit;

    int32_t act = 0b10000000;

    BITS_EQUAL(exp, act, mask);
}

TEST(test_assertions, masked_bit_low)
{
    int32_t mask = 0b10000000;

    int32_t bit = 7;
    int32_t exp = 0b11111111;
    exp &= ~(1UL << bit);

    int32_t act = 0b01111111;

    BITS_EQUAL(exp, act, mask);
}

TEST(test_assertions, int32_range)
{
    int32_t delta = 128;
    int32_t exp = 256;
    int32_t act = exp + delta;

    CHECK((act <= (exp + delta)) || (act >= (exp - delta)));
}

TEST(test_assertions, uint32_range)
{
    uint32_t delta = 128;
    uint32_t exp = 256;
    uint32_t act = exp + delta;

    CHECK((act <= (exp + delta)) || (act >= (exp - delta)));
}

TEST(test_assertions, float_range)
{
    float_t delta = 128.000f;
    float_t exp = 256.000f;
    float_t act = exp + delta;

    CHECK((act <= (exp + delta)) || (act >= (exp - delta)));
}

TEST(test_assertions, double_range)
{
    double_t  delta = 128.000;
    double_t  exp = 256.000;
    double_t  act = exp + delta;

    CHECK((act <= (exp + delta)) || (act >= (exp - delta)));
}

TEST(test_assertions, hex32_range)
{
    int32_t delta = 0x80u;
    int32_t exp = 0x100u;
    int32_t act = exp + delta;

    CHECK((act <= (exp + delta)) || (act >= (exp - delta)));
}

TEST(test_assertions, equal_ptr)
{
    int32_t value = 128;
    int32_t* exp = &value;
    int32_t* act = &*exp;

    POINTERS_EQUAL(exp, act);
}

TEST(test_assertions, equal_string)
{
    char exp[] = "assert";
    char act[] = "assert";

    STRCMP_EQUAL(exp, act);
}

TEST(test_assertions, equal_memory_block)
{
    const int32_t LENGTH = 32;
    int32_t* exp = (int32_t *)malloc(LENGTH * sizeof(int));

    if (!exp) {
        FAIL("Failed to allocate memory for 'int32_t* exp'");
        return;
    }

    int32_t* act = &*exp;
    MEMCMP_EQUAL(exp, act, LENGTH);
    free(act);
}

TEST(test_assertions, equal_int32_array)
{
    const int32_t LENGTH = 10;

    int32_t exp[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    int32_t act[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

    for (int i = 0; i < LENGTH; i++) LONGS_EQUAL(exp[i], act[i]);
}

TEST(test_assertions, equal_uint32_array)
{
    const int32_t LENGTH = 10;

    uint32_t exp[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    uint32_t act[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

    for (int i = 0; i < LENGTH; i++) LONGS_EQUAL(exp[i], act[i]);
}

TEST(test_assertions, equal_hex32_array)
{
    const int32_t LENGTH = 10;

    uint32_t exp[] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200 };
    uint32_t act[] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200 };

    for (int i = 0; i < LENGTH; i++) LONGS_EQUAL(exp[i], act[i]);
}

TEST(test_assertions, equal_float_array)
{
    const int32_t LENGTH = 10;

    float_t exp[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };
    float_t act[] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f };

    for (int i = 0; i < LENGTH; i++) DOUBLES_EQUAL(exp[i], act[i], 0.01);
}

TEST(test_assertions, equal_double_array)
{
    const int32_t LENGTH = 10;

    double_t exp[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
    double_t act[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };

    for (int i = 0; i < LENGTH; i++) DOUBLES_EQUAL(exp[i], act[i], 0.01);
}

TEST(test_assertions, equal_ptr_array)
{
    const int32_t LENGTH = 10;

    int32_t exp[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    int32_t* act = &exp[0];

    for (int i = 0; i < LENGTH; i++) POINTERS_EQUAL(exp[i], act[i]);
}

TEST(test_assertions, equal_string_array)
{
    const int32_t LENGTH = 3;

    char* exp[] = { "assert1", "assert2", "assert3" };
    char* act[] = { "assert1", "assert2", "assert3" };

    for (int i = 0; i < LENGTH; i++) STRCMP_EQUAL(exp[i], act[i]);
}

TEST(test_assertions, equal_memory_block_array)
{
    const int32_t LENGTH = 32;
    const int32_t BLOCKS = 4;

    int32_t* exp = (int32_t *)malloc(LENGTH * BLOCKS * sizeof(int32_t));

    if (!exp) {
        FAIL("Failed to allocate memory for 'int32_t* exp'");
        return;
    }

    int32_t* act = &*exp;
    for (size_t i = 0; i < BLOCKS; i++) MEMCMP_EQUAL(&exp[i * LENGTH], &act[i * LENGTH], LENGTH);
    free(act);
}

