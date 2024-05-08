#include <stdio.h>
#include "Headers/GeneralCiphers.h"

int main(void){
    char str1[] = "Hello,World!";
    char str2[] = "ROVVY,GYBVN!";
    printf("%s %s\n", ceasarCipher(str1,10), ceasarCipher(str2, 10, 'd'));
    return 0;
}