/*******************************************************************
* @Copyright          : Copyright 2024, SamRB-dev Turja Barua
* @File Name          : GeneralCiphers.h
* @Description        : A C/C++ header file containing functions to
                        to handle general cryptographic ciphers. 
* @Version            : 1.0
* @Github             : 
* @License            : CC-BY-NC        
/******************************************************************/ 

// Header files
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Constants~ */ 
const char ALPHABETS[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

/* Utility functions~ */
/*
    @params: char character
    @number_of_parameters: 1
    @return_type: int
    @returns: index of alphabets with range 0 to 26.
    @author: SamRB-dev
*/
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

/* Core Functions~ */
/*
    @params: string plainText, int Key, default value 5 (C++ feature)
    @number_of_parameters: 2
    @return_type: pointer -> string
    @returns: encrypted text.
    @author: SamRB-dev
    @reference: https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
*/
char *ceasarEncrypt(char plainText[], int Key = 5){
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