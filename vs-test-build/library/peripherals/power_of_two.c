#include "power_of_two.h"
#include <math.h>

static void* _read(Peripheral* self)
{
    return self->data;
}

static void _write(Peripheral* self, void* data)
{
    *(double*)self->data = pow(*(double*)data, 2);;
}

Peripheral create_power_of_two()
{
    return new_Peripheral(&_read, &_write, DOUBLE);
}
