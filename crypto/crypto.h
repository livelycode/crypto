
#ifndef CRYPTO
#define CRYPTO

#include <stdint.h>
#include <stdlib.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char Byte;
typedef _Bool Bool;
typedef int Integer;
typedef size_t Size;
typedef struct AES256Context AES256Context;
typedef struct SHA256Context SHA256Context;

#include "aes256.h"
#include "error.h"
#include "memory.h"
#include "sha256.h"

#endif
