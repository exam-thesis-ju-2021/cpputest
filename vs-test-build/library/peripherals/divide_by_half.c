#include "divide_by_half.h"
#include <stdio.h>

static void* _read(Peripheral* self)
{
    return self->data;
}

static void _write(Peripheral* self, void* data)
{
    *(double*)self->data = *(double*)data /= 2;;
}

Peripheral create_divide_by_half()
{
    return new_Peripheral(&_read, &_write, DOUBLE);
}
