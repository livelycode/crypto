
#ifndef CRYPTO_SHA256
#define CRYPTO_SHA256

#include "crypto.h"

/*
*/
Integer SHA256_digest_size(void);

/*
*/
SHA256Context *SHA256_create_context(void);

/*
*/
void SHA256_release_context(SHA256Context *context);

/*
*/
void SHA256_digest_init(SHA256Context *context);

/*
*/
void SHA256_digest_update(SHA256Context *context, Byte *digest, Size size);

/*
*/
void SHA256_digest_final(SHA256Context *context, Byte *digest);

#endif
