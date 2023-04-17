#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>



typedef struct mmatriz{
  int** matriz;
  int linha;
  int coluna;

}mmatriz;

typedef struct multiplicador{
mmatriz m1;
mmatriz m2;
mmatriz resultado;
int divisor;

}multiplicador;

void printmatriz(int linha, int coluna, int** matriz){
  for(int i = 0; i< linha; i++){
    printf("\n");
    for (int j = 0; j<coluna; j++){
      printf("%d ", matriz[i][j]);
    }
  }
  
    printf("\n");
}

void *criamatriz1(void* parametro){

  
   struct mmatriz* a = (struct mmatriz*)parametro;

    for(int i = 0; i< a->linha; i++){
    a->matriz[i] = (int*)calloc(a->coluna,sizeof(int));
    for (int j = 0; j<a->coluna; j++){
      a->matriz[i][j] = j*i + j + 1;
    }
  }

  
}


void *criamatriz2(void* parametro){
 
   struct mmatriz* a = (struct mmatriz*)parametro;

    for(int i = 0; i< a->linha; i++){
    a->matriz[i] = (int*)calloc(a->coluna,sizeof(int));
    for (int j = 0; j<a->coluna; j++){
      a->matriz[i][j] = i+j+1;
    }
  }

  
}

void *executarparte1(void* parametro){
 
   struct multiplicador* a = (struct multiplicador*)parametro;

  for(int i = 0; i< a->divisor; i++){
    a->resultado.matriz[i] = (int*)calloc(a->resultado.coluna,sizeof(int));
    
    for(int z = 0; z<a->resultado.coluna; z++){
      int temp = 0;
      int indicelinha = 0;
      int indicecoluna =0;
      while(indicecoluna < a->m1.coluna && indicelinha < a->m2.linha){
        
        temp = temp + a->m1.matriz[i][indicecoluna] * a->m2.matriz[indicelinha][z];
        indicelinha++;
        indicecoluna++;
      }

      a->resultado.matriz[i][z] = temp;
    }

  }

    

  
}


void *executarparte2(void* parametro){
 
   struct multiplicador* a = (struct multiplicador*)parametro;

  for(int i = a->divisor; i< a->resultado.linha; i++){
    a->resultado.matriz[i] = (int*)calloc(a->resultado.coluna,sizeof(int));
    
    for(int z = 0; z<a->resultado.coluna; z++){
      int temp = 0;
      int indicelinha = 0;
      int indicecoluna =0;
      while(indicecoluna < a->m1.coluna && indicelinha < a->m2.linha){
        
        temp = temp + a->m1.matriz[i][indicecoluna] * a->m2.matriz[indicelinha][z];
        indicelinha++;
        indicecoluna++;
      }

      a->resultado.matriz[i][z] = temp;
    }

  }

    

  
}
  
   
int main(void) {

  struct mmatriz smatriz, smatriz2, smatriz3;
  //Usarei 2 threads , porque segundo o site https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/cpu-options-supported-instances-values.html temos 1 core valido e esse core permite o uso de 2 threads.



  smatriz.linha = 3;
  
  smatriz.coluna = 2;
  int **matriz1 = calloc(smatriz.linha, sizeof(int*));

  smatriz.matriz = matriz1;


  
  smatriz2.linha = 2;
  smatriz2.coluna = 3;

  int **matriz2 = calloc(smatriz2.linha, sizeof(int*));
  smatriz2.matriz = matriz2; 
  // separar a criacao das duas matrizes
  pthread_t thread_1;
  pthread_t thread_2;

  //o uso da estrutura mmatriz eh para passar mais de um conteudo como argumento
  pthread_create (&thread_1,NULL,criamatriz1, (void*)&smatriz);
  pthread_create (&thread_2,NULL,criamatriz2, (void*)&smatriz2);

  pthread_join(thread_1, NULL);
  pthread_join(thread_2, NULL);

  printmatriz(smatriz.linha, smatriz.coluna, smatriz.matriz);
  printmatriz(smatriz2.linha, smatriz2.coluna, smatriz2.matriz);
  
  //multiplicacao


  
  smatriz3.linha = smatriz.linha;
  smatriz3.coluna = smatriz2.coluna;
  
  int **matriz3 = calloc(smatriz3.linha, sizeof(int*));
  smatriz3.matriz = matriz3;
  int divisao = smatriz.linha % 2; 
  int l1 = smatriz.linha-divisao-1;
  // dividir a matriz por linhas, primeiro codigo faz de 0 a l1 e a segunda thread de l1 ate o fim

  
  struct multiplicador final ;
  final.m1 = smatriz;
  final.m2 = smatriz2;
  final.resultado = smatriz3;
  final.divisor = l1;


  pthread_create (&thread_1,NULL,executarparte1, (void*)&final);

  pthread_create (&thread_2,NULL,executarparte2, (void*)&final);
  pthread_join(thread_1, NULL);
  pthread_join(thread_2, NULL);
  

  printmatriz(smatriz3.linha, smatriz3.coluna, smatriz3.matriz);
  

    
  

  printf("\n");
  return 0;
}
