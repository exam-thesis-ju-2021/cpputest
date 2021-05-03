#include "peripheral.h"
#include <stdlib.h>
#include <stdbool.h>

static void* alloc_by_type(DataType type) 
{
    void* ptr = NULL;

    switch (type) 
    {
    case BOOLEAN:
        ptr = malloc(sizeof(bool));
        break;
    case INTEGER:
        ptr = malloc(sizeof(int));
        break;
    case UINTEGER:
        ptr = malloc(sizeof(unsigned int));
        break;
    case STRING:
        ptr = malloc(sizeof(char*));
        break;
    case LONG:
        ptr = malloc(sizeof(long));
        break;
    case DOUBLE:
        ptr = malloc(sizeof(double));
        break;
    }

    return ptr;
}

Peripheral new_Peripheral(func_read_ptr read, func_write_ptr write, DataType type)
{
    Peripheral peripheral;
    peripheral.data = alloc_by_type(type);
    peripheral.type = type;
    peripheral.read = read;
    peripheral.write = write;
    return peripheral;
}

void destroy_Peripheral(Peripheral peripheral) 
{
    free(peripheral.data);
}