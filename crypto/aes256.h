
#ifndef CRYPTO_AES256
#define CRYPTO_AES256

#include "crypto.h"

/*
*/
Integer AES256_key_size(void);

/*
*/
Integer AES256_iv_size(void);

/*
*/
void AES256_create_key(Byte *buffer);

/*
*/
void AES256_create_iv(Byte *buffer);

/*
*/
AES256Context *AES256_create_context(void);

/*
*/
void AES256_release_context(AES256Context *context);

/*
*/
Integer AES256_cipher_size(Integer plain_size);

/*
*/
void AES256_encrypt_init(AES256Context *context, Byte *key, Byte *iv);

/*
*/
void AES256_decrypt_init(AES256Context *context, Byte *key, Byte *iv);

/*
*/
Integer AES256_encrypt_update(AES256Context *context, Byte *plain_text, Integer plain_size, Byte *cipher_text);

/*
*/
Integer AES256_decrypt_update(AES256Context *context, Byte *cipher_text, Integer cipher_size, Byte *plain_text);

/*
*/
Integer AES256_encrypt_final(AES256Context *context, Byte *cipher_text);

/*
*/
Integer AES256_decrypt_final(AES256Context *context, Byte *plain_text);

#endif
