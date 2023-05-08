#include <stdio.h>
#include <gmp.h>

int main() {
  mpf_set_default_prec(65536);  // Define a precisão padrão para 256 bits
  mpf_t e, termo, um, um_sobre_n;
  mpf_init(e);
  mpf_init(termo);
  mpf_init_set_ui(um, 1); // Inicializa um com o valor 1
  mpf_init(um_sobre_n);

  int n = 5000000; // Define o número de termos para calcular

  for(int i = 0; i <= n; i++) {
    mpf_div_ui(um_sobre_n, um, i+1);
    mpf_add_ui(termo, um_sobre_n, 1);
    mpf_pow_ui(termo, termo, i);
    mpf_add(e, e, termo);
  }

  gmp_printf("O valor de e é %.10000Ff\n", e);

  // Libera a memória alocada para as variáveis mpf_t
  mpf_clear(e);
  mpf_clear(termo);
  mpf_clear(um);
  mpf_clear(um_sobre_n);

  return 0;
}
