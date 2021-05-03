/*#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"


extern "C"
{
#include "pythagorean.h"
}


TEST_GROUP(Pythagorean)
{
    void setup() {
    }


    void teardown() {
        mock().clear();
    }

};

void productionCode()
{
    mock().actualCall("SquareRoot_sqrt");
}

TEST(Pythagorean, simpleTest)
{
    // arrange
    mock().expectOneCall("SquareRoot_sqrt").andReturnValue(5);

    // act
    int hypotenuse = Pythagorean_hypotenuse(3, 4);

    // assert
    mock().checkExpectations();
    CHECK_EQUAL(5, hypotenuse);
}
*/