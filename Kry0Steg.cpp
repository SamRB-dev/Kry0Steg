#include <stdio.h>
#include "Headers/GeneralCiphers.h"

int main(void){
    char str1[] = "Hello,World!";
    char str2[] = "MJQQT,BTWQI!";
    printf("%s %s\n", ceasarCipher(str1,5), ceasarCipher(str2, 5, 'd'));
    return 0;
}