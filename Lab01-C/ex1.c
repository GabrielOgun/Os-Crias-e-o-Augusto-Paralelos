#include  <stdio.h>
int lematriz(int linha, int coluna, int matriz[linha][coluna]){
int menor;
for (int i = 0 ; i<linha ; i++){
for (int j =0; j<coluna;j++){
if(i ==0 && j ==0){
 menor = matriz[i][j];
}
else{
if(matriz[i][j] < menor) menor = matriz[i][j];
}
}
}
return menor;
}


int main(){
int matriz[2][2] = {{-1,0},{10,5}};
printf("\n\nMenor valor da matriz: %d\n\n",lematriz(2,2,matriz));
}
