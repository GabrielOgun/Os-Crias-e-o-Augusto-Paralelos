#include <stdio.h>
#include <string.h>

int acha_caracter(char *frase, char x) {
    int i;
    int y;
    for (i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == x) {
            y =  i;
            printf(" o caracter aparece na posição %d na string\n", y);
        }
    }
    return -1; 
}

int main() {
    char *str = "computacao paralela";
    printf ("Qual caracter voce quer achar na frase 'Computacao Paralela'? ");
    char x;
    scanf ("%c",&x);
    acha_caracter(str, x);
    return 0;
}
