#include <stdio.h>
// crie um programa capaz de multiplicar uma linha de uma matriz de inteiros por um dado numero. faça o mesmo para uma coluna. A matriz deve ser lida de teclado. 
int main(void) {
int matrix[100][100];
int linha,coluna,i,j,num,escolha;
printf("entre com a quantidade de linhas:\n");
scanf("%d",&linha);
printf("entre com a quantidade de colunas\n");
scanf("%d",&coluna);
printf("digite os numeros da matriz");
//colocando na matriz
for(i=0;i<linha;i++){
    for(j=0;j<coluna;j++){
        scanf("%d",&matrix[i][j]);
    }
  printf("\n");
}
//printa a matriz
for(i=0;i<linha;i++){
    for(j=0;j<coluna;j++){
        printf("%d \t",matrix[i][j]);}
  printf("\n");}


printf("entre com um numero que vai multiplicar\n");
scanf("%d", &num);
printf("escolha entre linha e coluna (0 para linha e 1 para coluna)\n");
scanf("%d", &escolha); 

  if (escolha == 0){
    int lugar;
    printf("escolha a linha (comece de 0) \n");
    scanf("%d", &lugar);
    for(j=0;j<coluna;j++){
      matrix[lugar][j] = matrix[lugar][j] * num;
      }
    printf("\n");
    }
  else if (escolha == 1) {
    int lugar;
    printf("escolha a coluna (comece de 0) \n");
    scanf("%d", &lugar);
    for(i=0;i<linha;i++){
      matrix[i][lugar] = matrix[i][lugar] * num;
      }
    printf("\n");
    }else return 0;
  
  ///printa a matriz
  for(i=0;i<linha;i++){
    for(j=0;j<coluna;j++){
        printf("%d \t",matrix[i][j]);}
  printf("\n");}

}

