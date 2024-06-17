/*******************************************************************
* @Copyright          : Copyright 2024, SamRB-dev
* @File Name          : HashFunctions.h
* @Description        : Simple Header for containing hashing methods
                        with different libraries.
* @Version            : 1.0
* @Github             : 
* @License            : CC-BY-NC        
/******************************************************************/ 

// Standard Headers
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <math.h>

// Dependencies
#include <openssl/md5.h>
#include <openssl/sha.h>

// Constants

namespace HashFunctions {
    /* Core Functions */
    std::string hash_MD5(std::string message = "Hello,World"){
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
        return generated_hash;
    }

    std::string hash_SHA1(std::string message = "Hello,World"){
        std::string generated_hash = "";
        unsigned char sha1Hash[SHA_DIGEST_LENGTH];
        SHA_CTX sha1;
        SHA1_Init(&sha1);
        SHA1_Update(&sha1, message.c_str(), message.size());
        SHA1_Final(sha1Hash, &sha1);
        for(int idx = 0; idx < SHA_DIGEST_LENGTH; idx++){
            char tempBuffer[3];
            sprintf(tempBuffer, "%02x", sha1Hash[idx]);
            generated_hash += tempBuffer;
        }
        return generated_hash;
    }

    std::string hash_SHA256(std::string message = "Hello,World"){
        std::string generated_hash = "";
        unsigned char sha256Hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, message.c_str(), message.size());
        SHA256_Final(sha256Hash, &sha256);
        for(int idx = 0; idx < SHA256_DIGEST_LENGTH; idx++){
            char tempBuffer[3];
            sprintf(tempBuffer, "%02x", sha256Hash[idx]);
            generated_hash += tempBuffer;
        }
        return generated_hash;
    }
}
