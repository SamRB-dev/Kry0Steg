#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Constants
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

char *ceasarEncrypt(char plainText[], int Key = 5){
	// Reference: https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
	int length = strlen(plainText);
	for (int index = 0; index < length; index++){
		if(isalpha(plainText[index])){
			char character = toupper(plainText[index]);
			int substitutionIndex = (getAlphaIndex(character) + Key) % 26;
			plainText[index] = ALPHABETS[substitutionIndex];
		}
		else plainText[index] = plainText[index];
	}
	return plainText;
}

int main(void){
	char str[] = "Hello,World!";
	printf("%s\n",ceasarEncrypt(str));
}
