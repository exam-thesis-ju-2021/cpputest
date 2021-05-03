#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include "peripheral.h"

struct peripherals {
    Peripheral (*divide_by_half)();
    Peripheral (*multiply_by_two)();
    Peripheral (*power_of_two)();
    Peripheral (*square_root)();
};

extern const struct peripherals Peripherals;

#endif
