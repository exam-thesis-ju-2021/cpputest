#include "CppUTest/TestHarness.h"

extern "C"
{


}

TEST_GROUP(test_exceptionHandling)
{
    void setup()
    {
    }

    void teardown()
    {

    }
};

//Can not continue testing if unexpected exeption is thrown. 
TEST(test_exceptionHandling, createException) {
	try
	{
		//int i = *(int*)0;
		throw "exception\n";
	}
	catch (...)
	{
		printf("exception catched");
	}
}

TEST(test_exceptionHandling, verifyThatProgramKeptRunning) {
	CHECK_EQUAL(1, 1);
}
