#include <stdio.h>
#include <string>

std::string text2hex(std::string plainText){
    int length = plainText.length();
    std::string stringBuffer;
    for (int idx = 0;idx < length;idx++){
        char tempBuffer[3];
        sprintf(tempBuffer, "%02x", plainText[idx]);
        stringBuffer += tempBuffer;
    }
    return stringBuffer;
}
