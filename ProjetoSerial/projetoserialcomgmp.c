#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int main(void) {
  mpf_set_default_prec(256);

  mpf_t n;
  mpf_init_set_ui(n, 10000);

  mpf_t my_result;
  mpf_init_set_ui(my_result, 0);

  mpf_t *fatorial;
  fatorial = (mpf_t*)calloc((unsigned long)mpf_get_ui(n), sizeof(mpf_t));
  for(unsigned long i = 0; i < mpf_get_ui(n); i++) {
    mpf_init(fatorial[i]);
    if(i >= 1)
      mpf_mul_ui(fatorial[i], fatorial[i-1], i);
    else
      mpf_set_ui(fatorial[i], 1);

    mpf_t frac;
    mpf_init(frac);
    mpf_ui_div(frac, 1, fatorial[i]);
    mpf_add(my_result, my_result, frac);
    mpf_clear(frac);
  }

  gmp_printf("%.75Ff\n", my_result);

  for(unsigned long i = 0; i < mpf_get_ui(n); i++) {
    mpf_clear(fatorial[i]);
  }
  free(fatorial);

  mpf_clear(my_result);
  mpf_clear(n);
  
  return 0;
}
