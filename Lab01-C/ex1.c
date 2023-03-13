#include  <stdio.h>
int lematriz(int linha, int coluna, int matriz[linha][coluna]){
int menor;
int indice;
for (int i = 0 ; i<linha ; i++){
for (int j =0; j<coluna;j++){
if(i ==0 && j ==0){
 menor = matriz[i][j]; indice = i;
}
else{
if(matriz[i][j] < menor){ menor = matriz[i][j]; indice = i;}
}
}
}
return indice;;
}


int main(){



int matriz[2][2] = {{-1,0},{10,5}};


for (int i = 0; i < 2; i++){
    printf("\n");
    for (int j = 0; j<2; j++){
        printf(" %d ", matriz[i][j]);
    }
}


printf("\n\nMenor valor da matriz fica na linha: %d\n\n",lematriz(2,2,matriz));
}
