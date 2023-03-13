#include <stdio.h>
int main(){


int valor =2;

while(valor % 2 != 1){
printf("\n\nInforme um valor impar: ");
scanf("%d",&valor);

}

int vetor[valor];

for (int i = 0; i<valor; i++)vetor[i]=i+1;

for(int  j =0;j<(valor/2)+1;j++){
printf("\n");
for(int z = j; z<(valor-j);z++){
printf("%d", vetor[z]);
}
}


printf("\n\n");
}
