//Tudo nesse código ta em double para evitar o erro que encontramos de dar nan (not a number) por tentar somar tipos diferentes de dados.
#include <stdio.h>
#include <stdlib.h>
int main(void) {
 long double n = 10000;
 long double my_result = 0;
 long double fatorial = 0; 
// nao precisa ter uma lista, basta apenas uma variável já que so vamos acessar o ultimo termo ent so alterar a variável
/*optamos por o uso da variável fatorial porque ela terá acesso rápido e não precisaremos recalcular
toda vez valores que foram calculados anteriormente, já que o programa segue uma logica de ir
aumentando em 1 os fatoriais , basta pegar o ultimo valor e multiplicar pelo atual */
 for(int i =0; i<n; i++){
 if(i >= 1) fatorial = fatorial*i;

 else {
 fatorial = 1;
 }
 my_result = my_result + (1/fatorial);
 }
// nao chamamos outras funções porque além de não precisar prejudica a velocidade.
 printf("\n%.62Lf\n", my_result); // print com 62 casas pq era ate onde estava chegando, mas so esta certa ate a 18-19
 return 0;
}
