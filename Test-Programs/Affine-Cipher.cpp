#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
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
            int charIdx = getAlphaIndex(plainChar);
            int cipherIndex = ((key_1 * charIdx) + key_2) % 26;
            cipherText += ALPHABETS[cipherIndex];
        }
    }
    return cipherText;
}

std::string AffineCipherDecrypt(std::string cipherText, int key_1 = 5, int key_2 = 8){
    int length = cipherText.length();
    int modular_inverse = -1;
    std::string plainText = "";
    // Check if key_1 & 26 are coprime (GCD = 1)
    if (std::gcd(key_1, 26) == 1) {
        // Find modular multiplacative inverse
        int mod_key_1 = key_1 % 26;
        for(int iter = 1; iter < 26; iter++){
            if (((mod_key_1 * iter) % 26) == 1){
                modular_inverse = iter;
                break;
            }
        }
    }
    
    // printf("%d\n", modular_inverse);
    if (modular_inverse != -1){
        for (int idx = 0; idx < length; idx++){
            if (!isalpha(cipherText[idx]))
                plainText += cipherText[idx];
            else {
                char cipheredChar = toupper(cipherText[idx]);
                int charIdx = getAlphaIndex(cipheredChar);
                // Decryption Equation
                int plainIndex = (modular_inverse * abs((charIdx - key_2 + 26))) % 26;
                plainText += ALPHABETS[plainIndex];
            }
        }
        return plainText;
    } else
        return "Decryption Not Possible";
}

int main(void) {
    printf("%s\n",AffineCipherEncrypt("Hello,World").c_str());
    printf("%s\n",AffineCipherDecrypt("RCLLA,OAPLX").c_str());
    return 0;
}
