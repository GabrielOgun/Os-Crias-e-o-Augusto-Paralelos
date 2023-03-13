#include <stdio.h>

//printa matrix
void imprimematrix(int linha, int coluna, int matrix[linha][coluna]){
for(int i=0;i<linha;i++){
    for(int j=0;j<coluna;j++){
        printf("%d \t", matrix[i][j]);}
  printf("\n");}
  }



void somaL1L2(int linha, int coluna, int matrix[linha][coluna] ){
   for(int j=0;j<coluna;j++){
      matrix[1][j] = matrix[0][j] + matrix[1][j];
}
imprimematrix(linha,coluna,matrix);
  }
  

  
void multiL1L2(int linha, int coluna, int matrix[linha][coluna] ){
   for(int j=0;j<coluna;j++){
      matrix[1][j] = matrix[0][j] * matrix[1][j];
}
imprimematrix(linha,coluna,matrix);
  }





int main(void) {

  int matrix[3][3] = {1,2,3,4,5,6,7,8,9};


printf("\n\nOriginal:\n "); 

  imprimematrix(3,3,matrix);

printf("\n");

printf("Soma L1 e L2 \n");
 somaL1L2(3,3,matrix);
 printf("\n");

 printf("Multiplicacao L1 X L2 \n");
 multiL1L2(3,3,matrix);
  
}
