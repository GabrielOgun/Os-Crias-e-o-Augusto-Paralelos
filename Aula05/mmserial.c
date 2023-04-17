#include <stdio.h>
#include <stdlib.h>


void printmatriz(int linha, int coluna, int** matriz){
  for(int i = 0; i< linha; i++){
    printf("\n");
    for (int j = 0; j<coluna; j++){
      printf("%d ", matriz[i][j]);
    }
  }
  
    printf("\n");
}

int main(void) {



  int linhas1 = 3;
  int colunas1 = 2;

  int **matriz1 = calloc(linhas1, sizeof(int*));

  for(int i = 0; i< linhas1; i++){
    matriz1[i] = (int*)calloc(colunas1,sizeof(int));
    for (int j = 0; j<colunas1; j++){
      matriz1[i][j] = j*i + j + 1;
    }
  }
  

  
  int linhas2 = 2;
  int colunas2 = 3;

  int **matriz2 = calloc(linhas2, sizeof(int*));

  for(int i = 0; i< linhas2; i++){
    matriz2[i] = (int*)calloc(colunas2,sizeof(int));
    for (int j = 0; j<colunas2; j++){
      matriz2[i][j] = i+j+1;
    }
  }

  
  printmatriz(linhas1, colunas1,matriz1);

  printmatriz(linhas2, colunas2,matriz2);
  

  int cfinal = colunas2;
  int lfinal = linhas1;

  int **matriz3 = calloc(lfinal, sizeof(int*));

  for(int i = 0; i< lfinal; i++){
    matriz3[i] = (int*)calloc(cfinal,sizeof(int));
    
    for(int z = 0; z<cfinal; z++){
      int temp = 0;
      int indicelinha = 0;
      int indicecoluna =0;
      while(indicecoluna < colunas1 && indicelinha < linhas2){
        
        temp = temp + matriz1[i][indicecoluna] * matriz2[indicelinha][z];
        indicelinha++;
        indicecoluna++;
      }

      matriz3[i][z] = temp;
    }

  }


  printmatriz(lfinal, cfinal, matriz3);

  printf("\n");
  return 0;
}
