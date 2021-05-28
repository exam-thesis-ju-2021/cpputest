#include "CppUTest/TestHarness.h"

extern "C"
{
}

TEST_GROUP(test_fixtures)
{
    void setup()
    {
        printf("Verifying that setup() is executed.\n");
    }

    void teardown()
    {
        printf("Verifying that teardown() is executed.\n");
    }
};

TEST(test_fixtures, verification) 
{
    CHECK(true == true);
    printf("Verifying that test_fixtures() has been run in between setup() and tearDown().\n");
}