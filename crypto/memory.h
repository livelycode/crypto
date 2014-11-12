
#ifndef CRYPTO_MEMORY
#define CRYPTO_MEMORY

#include "crypto.h"

/*
*/
void *memory_alloc(Size size);

/*
*/
void memory_dealloc(void *buffer);

#endif
