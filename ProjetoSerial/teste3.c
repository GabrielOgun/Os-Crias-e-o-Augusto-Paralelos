#include <stdio.h>
#include <mpir.h> // biblioteca focada em aritmetica
#include <stdlib.h>

int main(void) {
    mpz_t n; // declarar como tipo inteiro da biblioteca MPIR
    mpz_init_set_ui(n, 5000000); // atribuir valor a uma variável
    mpf_t my_result;
    mpf_init_set_ui(my_result, 0);
    mpf_t fatorial;
    mpf_init_set_ui(fatorial, 0);

    for (unsigned long int i = 0; i < mpz_get_ui(n); i++) {
        /*unsigned long int vai de 0 a 4.294.967.295, portanto por ser um expoente vai sentido ir de 0 a um
        numero alto para podermos testar a precisão e por o problema iniciar com o fatorial de um numero
        positivo. */
        if (i >= 1)
            mpf_mul_ui(fatorial, fatorial, i); // jeito de fazer a multiplicação da biblioteca (onde armazenar resultado, fator1, fator2);
        else
            mpf_set_ui(fatorial, 1);

        mpf_t temp; // variável temporária para armazenar o resultado de 1/n! (não sabia como colocar esse valor direto no add, no caso sem passar por um intermediario)
        mpf_init(temp);
        mpf_ui_div(temp, 1, fatorial); // jeito de fazer a divisão da biblioteca (onde armazenar resultado, numero, divisor)
        mpf_add(my_result, my_result, temp);
        mpf_clear(temp); // limpar espaço usado para variável
    }

    mpfr_t result;
    mpfr_init(result);
    mpfr_set_f(result, my_result, MPFR_RNDN); // converter para o tipo mpfr da biblioteca MPIR
    mpfr_printf("%.10000Rf\n", result); // precisão alcançada com precisão

    mpf_clear(my_result);
    mpf_clear(fatorial);
    mpz_clear(n);
    mpfr_clear(result);

    return 0;
}
