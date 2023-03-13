#include <stdio.h>

//10 crie um funçao capaz de subistituir todos os numeros negativos de uma matriz por seu modulo


//printa matrix
void imprimematrix(int linha, int coluna, int matrix[linha][coluna]){
for(int i=0;i<linha;i++){
    for(int j=0;j<coluna;j++){
        printf("%d \t", matrix[i][j]);}
  printf("\n");}
  }



//funçao que escolhe o num e qual linha
void multplicaLinha(int num, int posição, int linha, int coluna, int matrix[linha][coluna]){
  for(int j=0;j<coluna;j++){
      matrix[posição-1][j] = matrix[posição-1][j] * num;
}
return imprimematrix(linha,coluna,matrix);
  }

//funçao que escolhe o nume e qual coluna
void multiplicacoluna(int num, int posição, int linha, int coluna, int matrix[linha][coluna]){
  for(int i=0;i<linha;i++){
      matrix[i][posição-1] = matrix[i][posição-1] * num;
      }


    printf("\n");    
    return imprimematrix(linha,coluna,matrix);

}




int main(void) {

  int matrix[3][3] = {1,-2,3,-4,5,6,7,8,-9};

  multplicaLinha(2, 2, 3,3,matrix);
  multiplicacoluna(2,1,3,3,matrix);
  

  
  return 0;
}
