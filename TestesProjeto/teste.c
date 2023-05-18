#include <stdio.h>
#include <mpfr.h>
#include <omp.h>

void calcular_serie_euler(unsigned long int start, unsigned long int end, mpfr_t resultado) {
    mpfr_t termo;
    mpfr_init(termo);
    mpfr_set_ui(resultado, 0, MPFR_RNDN);
    mpfr_set_ui(termo, 1, MPFR_RNDN);

    unsigned long int i;
    for (i = start; i <= end; i++) {
        mpfr_div_ui(termo, termo, i, MPFR_RNDN);

        #pragma omp critical
        {
            mpfr_add(resultado, resultado, termo, MPFR_RNDN);
        }
    }

    mpfr_clear(termo);
}

int main() {
    unsigned long int n = 1000000;

    // Definir a precisão desejada
    mpfr_set_default_prec(800000);

    mpfr_t serie;
    mpfr_init(serie);

    mpfr_t my_result;
    mpfr_init(my_result);
    mpfr_set_ui(my_result, 0, MPFR_RNDN);

    #pragma omp parallel num_threads(2)
    {
        int thread_id = omp_get_thread_num();
        unsigned long int start, end;

        if (thread_id == 0) {
            start = 1;
            end = n / 2;
        } else {
            start = n / 2 + 1;
            end = n;
        }

        calcular_serie_euler(start, end, my_result);
    }

    // Abrir arquivo para escrita
    FILE *arquivo = fopen("resultado.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Converter o resultado para uma string formatada
    char str_resultado[800001];
    mpfr_sprintf(str_resultado, "%.800000Rf", my_result);


    mpfr_clear(serie);
    mpfr_clear(my_result);

    return 0;
}
