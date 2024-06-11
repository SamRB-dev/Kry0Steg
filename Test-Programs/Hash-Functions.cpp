#include <stdio.h>
#include <string>
#include <openssl/md5.h>

void hash_MD5(std::string message) {
    std::string generated_hash = "";
    unsigned char md5Hash[MD5_DIGEST_LENGTH];
    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5, message.c_str(), message.size());
    MD5_Final(md5Hash, &md5);
    for(int idx = 0; idx < MD5_DIGEST_LENGTH; idx++){
        char tempBuffer[3];
        sprintf(tempBuffer, "%02x", md5Hash[idx]);
        generated_hash += tempBuffer;
    }
    printf("%s\n", generated_hash.c_str());
}

int main(void) {
    printf("Hello\n");
    hash_MD5("Hello,World");
    return 0;
}