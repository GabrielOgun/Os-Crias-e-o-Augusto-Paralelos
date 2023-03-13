#include <stdio.h>
#include <stdlib.h>

int** transposta(int tamanho, int matriz[tamanho][tamanho]){



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



int matriz[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

printf("\n\nMatriz Original");
for (int i = 0; i<3;i++){
printf("\n");
for(int j =0; j<3;j++){
printf(" %d ", matriz[i][j]);
}
}
int **matrizt = transposta(3,matriz);


printf("\n\nMatriz Transposta");
for (int i = 0; i<3;i++){
printf("\n");
for(int j =0; j<3;j++){
printf(" %d ", matrizt[i][j]);
}
}

printf("\n");
}
