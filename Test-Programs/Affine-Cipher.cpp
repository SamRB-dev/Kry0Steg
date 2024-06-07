#include <stdio.h>
#include <ctype.h>
#include <string>
#include <numeric>

const char ALPHABETS[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

int getAlphaIndex(char character){
	int index;
	for(int idx = 0; idx < 26; idx++){
		if (ALPHABETS[idx] == character){
			index = idx;
			break;
		}
	}
	return index;
}

std::string AffineCipherEncrypt(std::string plainText, int key_1 = 5, int key_2 = 8){
    int length = plainText.length();
    std::string cipherText = "";
    for(int idx = 0; idx < length; idx++){
        if (!isalpha(plainText[idx]))
            cipherText += plainText[idx];
        else {
            char plainChar = toupper(plainText[idx]);
            int chidx = getAlphaIndex(plainChar);
            int cipherIndex = ((key_1 * chidx) + key_2) % 26;
            cipherText += ALPHABETS[cipherIndex];
        }
    }
    return cipherText;
}


std::string AffineCipherDecrypt(std::string cipherText, int key_1 = 5, int key_2 = 8){
    int length = cipherText.length();
    std::string plainText = "";
    for(int idx = 0; idx < length; idx++){
        if (!isalpha(cipherText[idx]))
            plainText += cipherText[idx];
        else {
            char cipherChar = toupper(cipherText[idx]);
            int chidx = getAlphaIndex(cipherChar);
            gcd(key_1, )
            plainText += ALPHABETS[cipherIndex];
        }
    }
    return plainText;
}

int main(void) {
    AffineCipherEncrypt("Hello,World");
    return 0;
}
