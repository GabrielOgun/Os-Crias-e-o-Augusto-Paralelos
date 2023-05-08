
#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define THREAD_COUNT 2
#define ITERATIONS 15500
#define MAX_WAIT_TIME 10 // Tempo máximo de espera em microssegundos

sem_t* factorial_semaphores;

void* factorial_thread(void* arg) {
  mpf_t* factorial_list = (mpf_t*) arg;

  mpf_t fatorial;
  mpf_init_set_ui(fatorial, 1);

  for(unsigned long int i = 0; i < ITERATIONS; i++) {
    mpf_mul_ui(fatorial, fatorial, i+1);
    mpf_init_set(factorial_list[i], fatorial);

    sem_post(&factorial_semaphores[i]); // Liberar o semáforo correspondente ao fatorial
  }

  mpf_clear(fatorial);
  pthread_exit(NULL);
}

void* math_thread(void* arg) {
  mpf_t* factorial_list = (mpf_t*) arg;

  mpf_t my_result;
  mpf_init_set_ui(my_result, 1);

  for(unsigned long int i = 0; i < ITERATIONS; i++) {
    mpf_t temp;
    mpf_init(temp);

    int sem_value = 0;
    sem_getvalue(&factorial_semaphores[i], &sem_value);

    if(sem_value == 0) { // Se o semáforo estiver bloqueado, esperar um tempo simbólico
      usleep(MAX_WAIT_TIME);
    }

    sem_wait(&factorial_semaphores[i]); // Adquirir o semáforo para acessar o fatorial

    mpf_ui_div(temp, 1, factorial_list[i]);
    mpf_add(my_result, my_result, temp);

    mpf_clear(temp);
  }

  gmp_printf("%.100000Ff\n", my_result);
  mpf_clear(my_result);
  pthread_exit(NULL);
}

int main(void) {
  mpf_set_default_prec(120000);

  factorial_semaphores = (sem_t*) malloc(ITERATIONS * sizeof(sem_t));
  for(unsigned long int i = 0; i < ITERATIONS; i++) {
    sem_init(&factorial_semaphores[i], 0, 0); // Inicializar os semáforos com valor 0
  }

  mpf_t* factorial_list = (mpf_t*) malloc(ITERATIONS * sizeof(mpf_t));
  for(unsigned long int i = 0; i < ITERATIONS; i++) {
    mpf_init_set_ui(factorial_list[i], 1); // Inicializar com valor 1
  }

  pthread_t threads[THREAD_COUNT];

  pthread_create(&threads[0], NULL, factorial_thread, (void*) factorial_list);
  pthread_create(&threads[1], NULL, math_thread, (void*) factorial_list);

  for(int i = 0; i < THREAD_COUNT; i++) {
    pthread_join(threads[i], NULL); // Aguardar o término de todas as threads
 
}

  for(unsigned long int i = 0; i < ITERATIONS; i++) {
    mpf_clear(factorial_list[i]); // Liberar memória dos fatoriais
    sem_destroy(&factorial_semaphores[i]); // Destruir os semáforos
  }

  free(factorial_list); // Liberar memória da lista de fatoriais
  free(factorial_semaphores); // Liberar memória dos semáforos

  return 0;
}
