
#include "sha256.h"

struct SHA256Context {
    EVP_MD_CTX lib_context;
};

const char *SHA256_error = "SHA256 operation failed";

Integer SHA256_digest_size(void) {
    const EVP_MD *hash = EVP_sha256();
    return EVP_MD_size(hash);
}

SHA256Context *SHA256_create_context(void) {
    SHA256Context *context = memory_alloc(sizeof(SHA256Context));
    if (context == NULL) {
        error(SHA256_error);
    }
    EVP_MD_CTX_init(&context->lib_context);
    return context;
}

void SHA256_release_context(SHA256Context *context) {
    memory_dealloc(context);
}

void SHA256_digest_init(SHA256Context *context) {
    const EVP_MD *type = EVP_sha256();
    if (EVP_DigestInit_ex(&context->lib_context, type, NULL) == 0) {
        error(SHA256_error);
    }
}

void SHA256_digest_update(SHA256Context *context, Byte *digest, Size size) {
    if (EVP_DigestUpdate(&context->lib_context, digest, size) == 0) {
        error(SHA256_error);
    }
}

void SHA256_digest_final(SHA256Context *context, Byte *digest) {
    if (EVP_DigestFinal_ex(&context->lib_context, digest, NULL) == 0) {
        error(SHA256_error);
    }
}
