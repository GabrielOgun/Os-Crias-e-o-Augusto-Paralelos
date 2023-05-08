#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define THREAD_COUNT 2
#define ITERATIONS 15500
#define MAX_WAIT_TIME 10 // Tempo máximo de espera em microssegundos
#define HASH_SIZE 5 // Tabela HASH
#define PRECISAO 125000

sem_t* factorial_semaphores;
mpf_t factorial_list[HASH_SIZE]; // Vetor de fatoriais
int last_index = 0; // Índice do último fatorial calculado

void* factorial_thread(void* arg) {

  mpf_t fatorial;
  mpf_init_set_ui(fatorial, 1);

  for(unsigned long int i = 0; i < ITERATIONS; i++) {
    mpf_mul_ui(fatorial, fatorial, i+1);

    // Armazenar o fatorial no índice correspondente na tabela hash
    mpf_init_set(factorial_list[i%HASH_SIZE], fatorial);

    // Liberar o semáforo correspondente ao fatorial
    sem_post(&factorial_semaphores[i%HASH_SIZE]);
  }

  mpf_clear(fatorial);
  pthread_exit(NULL);
}

void* math_thread(void* arg) {

  mpf_t my_result;
  mpf_init_set_ui(my_result, 1);

  for(unsigned long int i = 0; i < ITERATIONS; i++) {
    mpf_t temp;
    mpf_init(temp);

    int sem_value = 0;
    sem_getvalue(&factorial_semaphores[i%HASH_SIZE], &sem_value);

    if(sem_value == 0) { // Se o semáforo estiver bloqueado, esperar um tempo simbólico
      usleep(MAX_WAIT_TIME);
    }

    sem_wait(&factorial_semaphores[i%HASH_SIZE]); // Adquirir o semáforo para acessar o fatorial

    // Acessar o fatorial no índice correspondente na tabela hash
    mpf_ui_div(temp, 1, factorial_list[i%HASH_SIZE]);

    mpf_add(my_result, my_result, temp);

    mpf_clear(temp);
  }

  gmp_printf("%.100000Ff\n", my_result);
  mpf_clear(my_result);
  pthread_exit(NULL);
}

int main(void) {
  mpf_set_default_prec(PRECISAO);

  factorial_semaphores = (sem_t*) malloc(HASH_SIZE * sizeof(sem_t));
  for(unsigned long int i = 0; i < HASH_SIZE; i++) {
    sem_init(&factorial_semaphores[i], 0, 0); // Inicializar os semáforos com valor 0
  }

  pthread_t threads[THREAD_COUNT];

  pthread_create(&threads[0], NULL, factorial_thread, NULL);
  pthread_create(&threads[1], NULL, math_thread, NULL);

  for(int i = 0; i < THREAD_COUNT; i++) {
    pthread_join(threads[i], NULL); // Aguardar o término de todas as threads
  }

  for(unsigned long int i = 0; i <
HASH_SIZE; i++) {
sem_destroy(&factorial_semaphores[i]); // Destruir os semáforos
}

free(factorial_semaphores); // Liberar a memória alocada para os semáforos

for(int i = 0; i < HASH_SIZE; i++) {
mpf_clear(factorial_list[i]); // Liberar a memória alocada para os fatoriais
}

return 0;
}
