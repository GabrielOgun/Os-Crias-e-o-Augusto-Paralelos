#include <stdio.h>

void inserir_char(char frase[], char x, int y) {
    int contador = 0;
    while (frase[contador] != '\0') {
        contador++;
    }
    for (int i = contador; i >= y; i--) {
        frase[i + 1] = frase[i];
    }
    frase[y] = x;
}

int main() {
    char str[100] = "computacao paralela";
    printf ("Qual caracter voce quer inserir na frase 'Computacao Paralela'? ");
    char x;
    scanf ("%c",&x);
    printf ("Qual posição? ");
    int y;
    scanf ("%d",&y);
    inserir_char(str, x, y);
    printf("Após a inserção do caractere: %s\n", str);
    return 0;
}
