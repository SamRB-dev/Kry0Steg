#include <stdio.h>
#include <string>
std::string text2hex(std::string plainText){
    int length = plainText.length();
    std::string stringBuffer;
    for (int idx = 0;idx < length;idx++){
        char tempBuffer[5];
        sprintf(tempBuffer, "%02x ", plainText[idx]);
        stringBuffer += tempBuffer;
    }
    return stringBuffer;
}

// ToDo Hex to String 

int main() {
    std::string t2h = text2hex("12005");
    printf("%s\n", t2h.c_str());
	return 0;
}
