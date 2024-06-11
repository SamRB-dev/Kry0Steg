#include <stdio.h>
#include <ctype.h>
#include <string>

std::string atbash(std::string plainText){
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

int main(void){
    std::string str = atbash("Hello,WOrld");
    printf("%s\n", str.c_str());
    return 0;
}