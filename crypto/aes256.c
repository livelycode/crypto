
#include "aes256.h"

struct AES256Context {
    EVP_CIPHER_CTX lib_context;
};

const char *AES256_error = "AES256 operation failed";

Integer AES256_key_size(void) {
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    return EVP_CIPHER_key_length(cipher);
}

Integer AES256_iv_size(void) {
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    return EVP_CIPHER_iv_length(cipher);
}

void AES256_create_key(Byte *buffer) {
    int size = AES256_key_size();
    RAND_bytes(buffer, size);
}

void AES256_create_iv(Byte *buffer) {
    int size = AES256_iv_size();
    RAND_bytes(buffer, size);
}

AES256Context *AES256_create_context(void) {
    AES256Context *context = memory_alloc(sizeof(AES256Context));
    if (context == NULL) {
        error(AES256_error);
    }
    EVP_CIPHER_CTX_init(&context->lib_context);
    return context;
}

void AES256_release_context(AES256Context *context) {
    memory_dealloc(context);
}

Integer AES256_cipher_size(Integer plain_size) {
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    int block_size = EVP_CIPHER_block_size(cipher);
    return plain_size + block_size - 1;
}

void AES256_encrypt_init(AES256Context *context, Byte *key, Byte *iv) {
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    if (EVP_EncryptInit_ex(&context->lib_context, cipher, NULL, key, iv) == 0) {
        error(AES256_error);
    }
}

void AES256_decrypt_init(AES256Context *context, Byte *key, Byte *iv) {
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    if (EVP_DecryptInit_ex(&context->lib_context, cipher, NULL, key, iv) == 0) {
        error(AES256_error);
    }
}

Integer AES256_encrypt_update(AES256Context *context, Byte *plain_text, Integer plain_size, Byte *cipher_text) {
    int cipher_size = 0;
    if (EVP_EncryptUpdate(&context->lib_context, cipher_text, &cipher_size, plain_text, plain_size) == 0) {
        error(AES256_error);
    }
    return cipher_size;
}

Integer AES256_decrypt_update(AES256Context *context, Byte *cipher_text, Integer cipher_size, Byte *plain_text) {
    int plain_size = 0;
    if (EVP_DecryptUpdate(&context->lib_context, plain_text, &plain_size, cipher_text, cipher_size) == 0) {
        error(AES256_error);
    }
    return plain_size;
}

Integer AES256_encrypt_final(AES256Context *context, Byte *cipher_text) {
    int cipher_size = 0;
    if (EVP_EncryptFinal_ex(&context->lib_context, cipher_text, &cipher_size) == 0) {
        error(AES256_error);
    }
    return cipher_size;
}

Integer AES256_decrypt_final(AES256Context *context, Byte *plain_text) {
    int plain_size = 0;
    if (EVP_DecryptFinal_ex(&context->lib_context, plain_text, &plain_size) == 0) {
        error(AES256_error);
    }
    return plain_size;
}
