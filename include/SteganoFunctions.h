#include <stdio.h>
#include <ctype.h>
#include <string>

/* ToDo > Second approach: Use regex to find index of all space and extract data from first order. */
namespace SteganoFunctions {
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
}