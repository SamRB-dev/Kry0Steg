#include <stdio.h>
#include <ctype.h>
#include <string>
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

void AffineCipherEncrypt(std::string plainText, int key_1 = 5, int key_2 = 8){
    int length = plainText.length();
    std::string cipherText = "";
    for(int idx = 0; idx < length; idx++){
        if (!isalpha(plainText[idx]))
            cipherText += plainText[idx];
        else {
            char plainChar = toupper(plainText[idx]);
            int chidx = getAlphaIndex(plainChar);
            int cipherIndex = ((key_1 * chidx) + key_2) % 26;
            printf("%d %d %c\n", chidx, cipherIndex, ALPHABETS[cipherIndex]);
        }
    }
}
int main(void) {
    AffineCipherEncrypt("Hello,World");
    return 0;
}
