#include <stdio.h>
#include "Headers/GeneralCiphers.h"
#include "Headers/HashFunctions.h"

int main(void){
    char str1[] = "Hello,World!";
    char str2[] = "ROVVY,GYBVN!";
    printf("%s %s\n", caesarCipher(str1,10), caesarCipher(str2, 10, 'd'));
    printf("%s\n", hash_SHA256().c_str());
    return 0;
}