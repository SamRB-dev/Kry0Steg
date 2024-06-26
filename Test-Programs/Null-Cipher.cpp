#include <stdio.h>
#include <string>
#include <ctype.h>

std::string stego_nullCipher_firstOrder(std::string message) {
    int length = message.length();
    std::string hiddenText = "";
    for(int idx = 0; idx < length; idx++){
        if (idx == 0 && isalnum(message[idx])){
            hiddenText += message[idx];
        }
        if (message[idx] == ' '){
			// (idx + 1 < length) ? (hiddenText += message[idx+1]) : NULL;
            if (idx + 1 < length) {
                if (!isalnum(message[idx+1]) && (idx + 2 < length))
                    hiddenText += message[idx+2];
                else
                    hiddenText += message[idx + 1];
            }
		}
    }
    return hiddenText;
}

int main(void) {
    printf("%s\n",stego_nullCipher_firstOrder("4 score and 7 years ago").c_str());
    return 0;
}
