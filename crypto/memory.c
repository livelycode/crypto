
#include "memory.h"

void *memory_alloc(Size size) {
    return malloc(size);
}

void memory_dealloc(void *buffer) {
    free(buffer);
}
