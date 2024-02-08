#include <iostream>
#include <sstream>
#include <openssl/evp.h>
#include <iomanip>
#include "hashPassword.h"

using namespace std;

string hashPassword(string password) {
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL);
    EVP_DigestUpdate(mdctx, password.c_str(), password.size());
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLen;
    EVP_DigestFinal_ex(mdctx, hash, &hashLen);
    EVP_MD_CTX_free(mdctx);
    stringstream ss;
    ss << hex << setfill('0');
    for (unsigned int i = 0; i < hashLen; i++) {
        ss << setw(2) << static_cast<unsigned int>(hash[i]);
    }
    return ss.str();
}