
#include "crypto.h"

void SHA256_test(void) {
    Byte message[] = "abc";
    Byte digest[SHA256_digest_size()];
    SHA256Context *context = SHA256_create_context();
    SHA256_digest_init(context);
    SHA256_digest_update(context, message, 3);
    SHA256_digest_final(context, digest);
    for (Integer index = 0; index < SHA256_digest_size(); index += 1) {
        Byte byte = digest[index];
        printf("%02x", byte);
    }
    printf("\n");
}

int main(void) {
    SHA256_test();
}
