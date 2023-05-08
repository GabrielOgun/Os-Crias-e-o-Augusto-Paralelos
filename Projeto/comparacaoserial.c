#include <stdio.h>
#include <gmp.h> //biblioteca focada em aritmetica
#include <stdlib.h>
int main(void) {
 mpf_set_default_prec(205000); //precisao das contas , tudo a partir dessa linha vai ter essa precisao
 mpf_t n; //declarer como tipo float da linguagem
 mpf_init_set_ui(n, 15500); // atribuir valor a uma variavel
 mpf_t my_result;
 mpf_init_set_ui(my_result, 0);
 mpf_t fatorial;
 mpf_init_set_ui(fatorial, 0);
 for(unsigned long int i = 0; i < mpf_get_ui(n); i++) {
/*unsigned long int vai de 0 a 4.294.967.295, portanto por ser um expoente vai sentido ir de 0 a um
numero alto para podermos testar a precisão e por o problema iniciar com o fatorial de um numero
positivo. */
 if(i >= 1)
 mpf_mul_ui(fatorial, fatorial, i); // jeito de fazer a multiplicação da biblioteca (onde armazenar resultado, fator1, fator2);
 else
 mpf_set_ui(fatorial, 1);
 mpf_t temp; // variavel temporária para armazenar o resultado de 1/n! (não sabia como colocar esse valor direto no add, no caso sem passar por um intermediario)
 mpf_init(temp);
 mpf_ui_div(temp, 1, fatorial); // jeito de fazer a divisão da biblioteca (onde armazenar resultado, numero, divisor)
 mpf_add(my_result, my_result, temp);
 mpf_clear(temp); // limpar espaço usado para variavel
 }
 gmp_printf("%.70000Ff\n", my_result); // precisa alcançada com precisão
 mpf_clear(my_result);
 mpf_clear(n);
 mpf_clear(fatorial);

 return 0;
}
