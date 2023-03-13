#include <stdio.h>
#include <stdlib.h>

int** transposta(int tamanho, int **matriz){



 int **matrizt; 
 matrizt = malloc(sizeof(int*) * tamanho); 
 for(int i = 0; i < 3; i++) { 
 matrizt[i] = malloc(sizeof(int*) * tamanho); 
 } 

for (int i = 0; i<tamanho;i++){
for(int j =0; j<tamanho;j++){
matrizt[j][i] = matriz[i][j];
}
}

return  matrizt;
}

int main(){


int tamanho;
printf("\nTamanho da matriz quadratica: ");
scanf("%d", &tamanho);


 int **matriz; 
 matriz = malloc(sizeof(int*) * tamanho); 
 for(int i = 0; i < 3; i++) { 
 matriz[i] = malloc(sizeof(int*) * tamanho); 
 } 

for (int i = 0; i<tamanho;i++){
for(int j =0; j<tamanho;j++){
printf("\nEscolha um valor para posicao %d,%d: " , i+1, j+1);
scanf("%d", &matriz[i][j]);

}
}

printf("\n\nMatriz original");

for (int i = 0; i<tamanho;i++){
printf("\n");
for(int j =0; j<tamanho;j++){
printf(" %d ", matriz[i][j]);
}
}

int **matrizt = transposta(tamanho,matriz);


printf("\n\nMatriz transposta");

for (int i = 0; i<tamanho;i++){
printf("\n");
for(int j =0; j<tamanho;j++){
printf(" %d ", matrizt[i][j]);
}
}

printf("\n\n");
}
