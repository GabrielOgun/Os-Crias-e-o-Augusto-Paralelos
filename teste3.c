#include <stdio.h>
#include <gmp.h>
#include <omp.h>

#define THREAD_COUNT 2
#define ITERATIONS 15500
#define PRECISAO 125000

int main(void) {
  mpf_set_default_prec(PRECISAO);

  mpf_t my_result;
  mpf_init_set_ui(my_result, 1);

  #pragma omp parallel num_threads(THREAD_COUNT)
  {
    mpf_t fatorial;
    mpf_init_set_ui(fatorial, 1);

    #pragma omp for
    for(unsigned long int i = 1; i <= ITERATIONS; i++) {
      mpf_mul_ui(fatorial, fatorial, i);

      // Dividir 1 pelo fatorial e adicionar ao resultado parcial
      mpf_t temp;
      mpf_init(temp);
      mpf_ui_div(temp, 1, fatorial);

      #pragma omp critical
      mpf_add(my_result, my_result, temp);

      mpf_clear(temp);
    }

    mpf_clear(fatorial);
  }

  gmp_printf("%.100000Ff\n", my_result);
  mpf_clear(my_result);

  return 0;
}
