#include <stdio.h>


typedef struct Pessoa{
    
    int idade;
    float peso;
    char nome[60];
    
}Pessoa;
int main()
{
    
    
    int valor = 3;
    
    printf("\n");
    struct Pessoa lista[valor];
    for (int i =0; i<valor;i++){
        struct Pessoa nova;
        printf("\nInsira o nome da %da pessoa: ", i+1);
        scanf("%s", nova.nome);
        printf("\nInsira a idade da %da pessoa em anos: ", i+1);
        scanf("%d", &nova.idade);
        printf("\nInsira o peso da %da pessoa em kg: ", i+1);
        scanf("%f", &nova.peso);
        
        lista[i] = nova;
        
    }
    
    
    for (int i =0; i<valor;i++){
        printf("\n%s tem %d anos e pesa %.2f kg", lista[i].nome, lista[i].idade, lista[i].peso);
        
        
    }
    
printf("\n");
    
}
