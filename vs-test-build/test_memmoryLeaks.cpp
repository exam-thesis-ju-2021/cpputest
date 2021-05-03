#include "CppUTest/TestHarness.h"

extern "C"
{
}

TEST_GROUP(test_memmoryLeaks)
{
    void setup()
    {
    }

    void teardown()
    {
        
    }
};

TEST(test_memmoryLeaks, verification_of_memmory) {
    int* exp = (int*)malloc(100 * sizeof(int));
    int* act = (int*)malloc(100 * sizeof(int));

    if (exp == NULL || act == NULL)
        printf("Memory not allocated.\n");

    *exp = 5;
    *act = 5;

    MEMCMP_EQUAL(exp, act, sizeof(int));
    //free(act);
    //free(exp);
}