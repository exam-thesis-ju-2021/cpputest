#include "CppUTest/TestHarness.h"

extern "C"
{
#include "library/hardware.h"
}

void ASSERT_PIN_STATE(PinState expected, uint16_t gpio);

TEST_GROUP(Extensibility_test)
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

TEST(Extensibility_test, selfMade_assert)
{
	uint16_t pin = 4;
	digital_write(pin, HIGH);
	ASSERT_PIN_STATE(HIGH, 4);
}

void ASSERT_PIN_STATE(PinState expected, uint16_t gpio)
{
	char* output = (char*)malloc(128 * sizeof(char));

	if (digital_read(gpio) != expected)
	{
		sprintf(output, "Custom assertion '%s' failed.", __func__);
		FAIL(output);
	}

	free(output);
}