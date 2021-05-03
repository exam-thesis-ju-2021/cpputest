#ifndef PERIPHERAL_H
#define PERIPHERAL_H

#include <stdint.h>

typedef struct Peripheral Peripheral;
typedef void* (*func_read_ptr) (Peripheral* self);
typedef void (*func_write_ptr) (Peripheral* self, void* data);

typedef enum {
    UNDEFINED,
    BOOLEAN,
    INTEGER,
    UINTEGER,
    STRING,
    LONG,
    DOUBLE
} DataType;

typedef struct Peripheral {
	void* data;
    DataType type;
	func_read_ptr read;
	func_write_ptr write;
} Peripheral;

Peripheral new_Peripheral(func_read_ptr read, func_write_ptr write, DataType type);
void destroy_Peripheral(Peripheral peripheral);

#endif