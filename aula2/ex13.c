#include <stdio.h>

void remove_char(char frase[], int x) {
    int len = 0;
    while (frase[len] != '\0') {
        len++;
    }
    for (int i = x; i < len - 1; i++) {
        frase[i] = frase[i + 1];
    }
    frase[len - 1] = '\0';
}

int main() {
    char str[100] = "computacao paralela";
    printf ("Qual posição voce quer remover caracter na frase 'Computacao Paralela'? ");
    int x;
    scanf ("%d",&x);
    remove_char(str, x);
    printf("Após a remoção do caracter: %s\n", str);
    return 0;
}
