#include <stdio.h>
#include <pthread.h>
#include <gmp.h>
#include <stdlib.h>

#define NUM_THREADS 2
#define N 16050

mpf_t my_result;
mpf_t *fatorial;

void *calcular_fatorial(void *arg) {
    for(unsigned long int i = 0; i <= N; i++) {
        if(i >= 1) {
            mpf_init(fatorial[i]);
            mpf_mul_ui(fatorial[i], fatorial[i-1], i);
        } else {
            mpf_init_set_ui(fatorial[i], 1);
        }
    }
    pthread_exit(NULL);
}

void *calcular_resultado(void *arg) {
    mpf_t temp;
    mpf_init(temp);
    for(unsigned long int i = 0; i <= N; i++) {
        mpf_ui_div(temp, 1, fatorial[i]);
        mpf_add(my_result, my_result, temp);
    }
    pthread_exit(NULL);
}

int main(void) {
    mpf_set_default_prec(205000);
    mpf_init_set_ui(my_result, 0);
    fatorial = (mpf_t *)malloc(sizeof(mpf_t) * (N+1));

    pthread_t threads[NUM_THREADS];
    int rc;

    // Iniciar thread para calcular fatoriais
    rc = pthread_create(&threads[0], NULL, calcular_fatorial, NULL);
    if (rc) {
        printf("Erro ao criar thread para calcular fatoriais: %d\n", rc);
        exit(-1);
    }

    // Aguardar finalização da thread de cálculo de fatoriais
    rc = pthread_join(threads[0], NULL);
    if (rc) {
        printf("Erro ao aguardar thread de cálculo de fatoriais: %d\n", rc);
        exit(-1);
    }

    // Iniciar thread para calcular resultado
    rc = pthread_create(&threads[1], NULL, calcular_resultado, NULL);
    if (rc) {
        printf("Erro ao criar thread para calcular resultado: %d\n", rc);
        exit(-1);
    }

    // Aguardar finalização da thread de cálculo de resultado
    rc = pthread_join(threads[1], NULL);
    if (rc) {
        printf("Erro ao aguardar thread de cálculo de resultado: %d\n", rc);
        exit(-1);
    }

    gmp_printf("%.70000Ff\n", my_result);

    // Limpar memória alocada
    mpf_clear(my_result);
    for(unsigned long int i = 0; i <= N; i++) {
        mpf_clear(fatorial[i]);
    }
    free(fatorial);

    return 0;
}
