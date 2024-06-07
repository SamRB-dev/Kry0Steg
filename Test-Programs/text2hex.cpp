#include <stdio.h>
#include <string>
void text2hex(std::string plainText){
    int length = plainText.length();
    const char stringBuffer[length * 3];
    for (int idx = 0;idx < length;idx++){
        sprintf(stringBuffer, "%X", plainText[idx]);
    }
    std::string test = "Test + " + stringBuffer;
    printf("%s", test);
}

int main() {
    text2hex("ABC");
	return 0;
}
