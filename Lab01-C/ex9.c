#include <stdio.h>


//ex 9

void imprimematrix(int linha, int coluna, int matrix[linha][coluna]){
for(int i=0;i<linha;i++){
    for(int j=0;j<coluna;j++){
        printf("%d \t", matrix[i][j]);}
  printf("\n");}
  }




void modulo( int linha, int coluna, int matrix[linha][coluna]){
  
  for(int i=0;i<linha;i++){
    for(int j=0;j<coluna;j++){
        if(matrix[i][j] < 0){
          matrix[i][j] = matrix[i][j] *  -1;
          } 
    }
  printf("\n");
}
return imprimematrix(linha, coluna, matrix);
}





int main(void) {

  int matrix[3][3] = {1,-2,3,-4,5,6,7,8,-9};

  printf("matriz original \n");
  imprimematrix(3, 3, matrix);
  
  printf("matriz em modulo");
  modulo(3,3, matrix);
  
  return 0;
}
