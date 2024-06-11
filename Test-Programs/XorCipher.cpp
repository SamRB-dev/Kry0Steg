#include <stdio.h>
#include <string>

// cryptopals.com
void fixedXor(std::string encodedText, std::string key){
    if (encodedText.length() == key.length()) {
        std::string decipheredByteString;
        for(int idx = 0; idx < encodedText.length(); idx++){
            char buffer[5];
            sprintf(buffer, "%x" , ((int) encodedText[idx] ^ (int) key[idx]));
            decipheredByteString += buffer;
        }
        printf("%s\n", decipheredByteString.c_str());
    }
}
int main(void){
    // std::string str = "test";
    // for(int idx = 0; idx < str.length(); idx++){
    //     int decimal = (int) str[idx];
        
    // 
    fixedXor("1c0111001f010100061a024b53535009181c", "686974207468652062756c6c277320657965");
    return 0;
}