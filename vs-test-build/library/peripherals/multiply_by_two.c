#include "multiply_by_two.h"

static void* _read(Peripheral* self)
{
    return self->data;
}

static void _write(Peripheral* self, void* data)
{
    *(double*)self->data = *(double*)data * 2;;
}

Peripheral create_multiply_by_two()
{
    return new_Peripheral(&_read, &_write, DOUBLE);
}
