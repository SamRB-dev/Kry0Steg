/*******************************************************************
* @Copyright          : Copyright 2024, SamRB-dev
* @File Name          : GeneralCiphers.h
* @Description        : A C/C++ header file containing functions to
                        to handle general cryptographic ciphers. 
* @Version            : 1.0
* @Github             : https://github.com/SamRB-dev/Kry0Steg/blob/main/Headers/GeneralCiphers.h
* @License            : CC-BY-NC        
/******************************************************************/ 

// Header files
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <numeric>

/* Constants~ */ 
const char ALPHABETS[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

/* Utility functions~ */
/*
    @params: char character
    @number_of_parameters: 1
    @return_type: int
    @returns: index of alphabets with range 0 to 26.
    @author: SamRB-dev
*/
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

/* Core Functions~ */
char *caesarCipher(char plainText[], int Key = 5, char mode = 'e'){
	/*
    @params: string plainText, int Key, default value 5 (C++ feature)
    @number_of_parameters: 2
    @return_type: pointer -> string
    @returns: encrypted text.
    @author: SamRB-dev
    @reference: https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
	*/
	if (mode == 'e' || mode == 'd') {
		int length = strlen(plainText);
		for (int index = 0; index < length; index++){
			if(isalpha(plainText[index])){
				char character = toupper(plainText[index]);
				int substitutionIndex = (mode == 'e') ? ((getAlphaIndex(character) + Key) % 26) : 
				((getAlphaIndex(character) - Key) < 0) ? ((getAlphaIndex(character) - Key) + 26) : 
				((getAlphaIndex(character) - Key) % 26);
				plainText[index] = ALPHABETS[substitutionIndex];
			}
			else plainText[index] = plainText[index];
		}
	}
	return plainText;
}

std::string atbashCipher(std::string plainText = "Hello,World") {
	/*
    @params: string plainText, default value Hello,World (C++ feature)
    @number_of_parameters: 1
    @return_type: pointer -> string
    @returns: encrypted / decrypted text.
    @author: 
    @reference: https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
	*/
	std::string cipherText = "";
    int strLen = plainText.length();
    for(int idx = 0; idx < strLen; idx++){
        if (!isalpha(plainText[idx])) 
            cipherText += plainText[idx];
        else {
            char plainChar = toupper(plainText[idx]);
            cipherText += 'Z' - (plainChar - 'A');
        }
    }
    return cipherText;
}

std::string AffineCipherEncrypt(std::string plainText = "Hello,World", int key_1 = 5, int key_2 = 8){
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
        return "Operation Not Possible";
}
