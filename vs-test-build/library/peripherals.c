#include "peripherals.h"
#include "peripherals/divide_by_half.h"
#include "peripherals/multiply_by_two.h"
#include "peripherals/power_of_two.h"
#include "peripherals/square_root.h"

const struct peripherals Peripherals = {
    .divide_by_half = create_divide_by_half,
    .multiply_by_two = create_multiply_by_two,
    .power_of_two = create_power_of_two,
    .square_root = create_square_root
};