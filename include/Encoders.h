/*******************************************************************
* @Copyright          : Copyright 2024, SamRB-dev, Turja Barua
* @File Name          : Encoders.h
* @Description        : Simple Header for containing simple encoders
                        i.e text to hex.
* @Version            : 1.0
* @Github             : 
* @License            : BSD-3-Clause    
******************************************************************/ 

// Header files
#include <stdio.h>
#include <string>

namespace Encoders {
    std::string text2hex(std::string plainText){
         /*
        @params: string plainText
        @number_of_parameters: 1
        @return_type: string
        @returns: hex coded text
        @author: Turja Barua
        */
        int length = plainText.length();
        std::string stringBuffer;
        for (int idx = 0;idx < length;idx++){
            char tempBuffer[3];
            // sprintf, concats formatted data to buffer, tempBuffer
            sprintf(tempBuffer, "%02x", plainText[idx]);
            stringBuffer += tempBuffer;
        }
        return stringBuffer;
    }
}