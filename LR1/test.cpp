#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char buff[80];
    while(gets(buff)){
    if(!strcmp(buff,"Eliseev Nikita I992"))
        printf("Test pass!\n");
    else 
     printf("Test denied\n");
    }
    return 0;
}