#include <stdio.h>
#include <ctype.h>
int main(){

char nome[20];

char nome2[20];


for(int i =0; i<20; i++){
nome[i] = '\0';
nome2[i] = '\0';
}

printf("\n\nInsira o primeiro nome: ");
scanf("%s", nome);

printf("\nInsira o segundo nome: ");
scanf("%s", nome2);




int contador =0;
while(nome[contador] != '\0' && nome2[contador] != '\0'){

if(tolower(nome[contador]) < tolower(nome2[contador])){

printf("\n%s", nome);

printf("\n%s\n", nome2);
return 1;

}else{
if(tolower(nome[contador]) > tolower(nome2[contador])){

printf("\n%s", nome2);

printf("\n%s\n", nome);
return 1;

}else{contador++;}
}

}

printf("\n%s", nome);
printf("\n%s\n", nome2);
}


