#include "square_root.h"
#include <math.h>

static void* _read(Peripheral* self)
{
    return self->data;
}

static void _write(Peripheral* self, void* data)
{
    *(double*)self->data = sqrt(*(double*)data);
}

Peripheral create_square_root()
{
    return new_Peripheral(&_read, &_write, DOUBLE);
}
