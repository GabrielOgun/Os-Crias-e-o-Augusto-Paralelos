#include <stdio.h>
#include <pthread.h>
#include <gmp.h>
#include <stdlib.h>

#define NUM_THREADS 2
#define N 15500

mpf_t my_result;
unsigned long int *fatorial;
pthread_mutex_t mutex;

void *calcular_fatorial(void *arg) {
    for (unsigned long int i = 2; i <= N; i++) {
        pthread_mutex_lock(&mutex);
        fatorial[i] = fatorial[i - 1] * i;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *calcular_resultado(void *arg) {
    mpf_t temp;
    mpf_init(temp);
    for (unsigned long int i = 2; i <= N; i++) {
        pthread_mutex_lock(&mutex);
        mpf_set_ui(temp, fatorial[i]);
        mpf_t divisor;
        mpf_init(divisor);
        mpf_set_ui(divisor, 1);
        mpf_div(temp, divisor, temp);
        mpf_add(my_result, my_result, temp);
        mpf_clear(divisor);
        pthread_mutex_unlock(&mutex);
    }
    mpf_clear(temp);
    pthread_exit(NULL);
}

int main(void) {
    mpf_set_default_prec(205000);
    mpf_init_set_ui(my_result, 0);
    fatorial = (unsigned long int *)malloc(sizeof(unsigned long int) * (N + 1));

    fatorial[0] = 1;
    fatorial[1] = 1;

    pthread_t threads[NUM_THREADS];
    int rc;

    pthread_mutex_init(&mutex, NULL);

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
    free(fatorial);

    pthread_mutex_destroy(&mutex);

    return 0;
}
