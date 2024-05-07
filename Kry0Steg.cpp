#include <stdio.h>
#include "Headers/GeneralCiphers.h"

int main(void){
    char str[] = "Hello,World!";
    printf("%s\n",ceasarEncrypt(str));
    return 0;
}