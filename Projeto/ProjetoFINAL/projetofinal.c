#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 2
#define N 136500



mpz_t fatorial[N/2 + 1];
mpz_t fatorial2;
mpf_t rparcial, rparcial2, my_result;
sem_t semaphore;

void *calcular_fatorial(void *arg) {
    mpz_init_set_ui(fatorial[0], 1);
    for (int i = 1; i <= N/2; i++) {
        mpz_init(fatorial[i]);
        mpz_mul_ui(fatorial[i], fatorial[i - 1], i);
    }

    mpz_init(fatorial2);
    mpz_set(fatorial2, fatorial[N/2]);

    sem_post(&semaphore);

    mpf_t temp2;
    mpf_init(temp2);

for (int i = 0; i <= N/2; i++) {
    if (i > 0) {
        mpz_mul_ui(fatorial2, fatorial2, ((N/2) + i));
    }

    mpf_set_z(temp2, fatorial2); // Converter mpz_t para mpf_t
    mpf_ui_div(temp2, 1, temp2);
    mpf_add(rparcial2, rparcial2, temp2);
}

    mpf_clear(temp2);
    pthread_exit(NULL);
}
void *calcular_rparcial(void *arg) {
    // Esperar pelo cálculo do fatorial
    sem_wait(&semaphore);

    mpf_t temp;
    mpf_init(temp);

    for (int i = 0; i <= N/2; i++) {


        mpf_set_z(temp, fatorial[i]);
        mpf_ui_div(temp, 1, temp);
        mpf_add(rparcial, rparcial, temp);
        
        mpz_clear(fatorial[i]);
    }

    mpf_clear(temp);

    pthread_exit(NULL);
}

int main(void) {
    mpf_set_default_prec(1000000);
    mpf_init(rparcial);
    mpf_init(rparcial2);
    mpf_init(my_result);

    pthread_t thread_fatorial, thread_rparcial;

    sem_init(&semaphore, 0, 0);

    // Criação das threads
    pthread_create(&thread_fatorial, NULL, calcular_fatorial, NULL);
    pthread_create(&thread_rparcial, NULL, calcular_rparcial, NULL);

    // Aguardar finalização das threads
    pthread_join(thread_fatorial, NULL);
    pthread_join(thread_rparcial, NULL);

    // Adicionar rparcial a my_result
    mpf_add(my_result, rparcial, rparcial2);

    gmp_printf("My Result: %.301000Ff\n", my_result);

    // Limpar memória alocada
    mpf_clear(rparcial);
    mpf_clear(rparcial2);
    mpf_clear(my_result);

    sem_destroy(&semaphore);

    return 0;
}
