#include "CppUTest/TestHarness.h"

extern "C"
{
#include "library/hardware.h"
}

void ASSERT_PIN_STATE(PinState expected, uint16_t gpio);

TEST_GROUP(test_extensibility)
{
    void setup()
    {
        hardware_init();
    }

    void teardown()
    {
        hardware_reset();
    }
};

TEST(test_extensibility, extension)
{
	uint16_t pin = 4;
	digital_write(pin, HIGH);
	ASSERT_PIN_STATE(HIGH, 4);
}

void ASSERT_PIN_STATE(PinState expected, uint16_t gpio)
{
	printf("Executing extended assertion...\n");

	char* output = (char*)malloc(128 * sizeof(char));
	if (!output) {
		FAIL("Failed to allocate memory for 'char* output'");
		return;
	}

	if (digital_read(gpio) == expected)
	{
		sprintf(output, "Custom assertion '%s' passed.", __func__);
		CHECK_TEXT(true, output);
	}
	else
	{
		sprintf(output, "Custom assertion '%s' failed.", __func__);
		FAIL(output);
	}

	free(output);
}