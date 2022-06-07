#include <stdio.h>
#include <stdlib.h>
int main(){
    char c;
    FILE *file;
    file = fopen("quine.c","r");
    while((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    fclose(file);
    return 0;
}