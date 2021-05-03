#include "module_a.h"
#include "peripherals.h"
#include "hardware.h"
#include <stdio.h>

void init() 
{
	hardware_init();

	set_peripheral(0, Peripherals.divide_by_half());
	set_peripheral(1, Peripherals.multiply_by_two());
	set_peripheral(2, Peripherals.power_of_two());
	set_peripheral(3, Peripherals.square_root());

	for (int i = 0; i < 4; i++)
		digital_write(i, HIGH);
}

void reset()
{
	for (int i = 0; i < 4; i++)
		digital_write(i, LOW);
	
	hardware_reset();
}

double divide_by_half(double value)
{
	analog_write(0, &(double){value});
	return *(double*)analog_read(0);
}

double multiply_by_two(double value)
{
	analog_write(1, &(double){value});
	return *(double*)analog_read(1);
}

double power_of_two(double value)
{
	analog_write(2, &(double){value});
	return *(double*)analog_read(2);
}

double square_root(double value)
{
	analog_write(3, &(double){value});
	return *(double*)analog_read(3);
}