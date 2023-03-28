#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    
    
    int shmid = shmget(IPC_PRIVATE,sizeof(int),0644 | IPC_CREAT); // memoria compartilhada (IPC_PRIVATE padrao,sizeof(tipo --> tamanho que o dado ocupa na memoria), flag --> ver se o local ja nao tem uma memoria compartilhada 
    int *compartilhada = shmat(shmid, NULL, 0); // ponteiro para a memoria compartilhada, (memoriacompartilhada, endereco desejado, flags)
    int x = 1;
    *compartilhada = x;
    printf("Valor inicial:%d\n",*compartilhada);

    if (fork() == 0)
    {
        *compartilhada = *compartilhada + 2;     
        printf("Filho: %d\n", *compartilhada);
       
        exit(0);
    }
    else{ // Sem isso tava dando 4 ou 6
        wait(NULL);
    }
  
    *compartilhada = *compartilhada*4;
    printf("Valor final: %d\n", *compartilhada);


    return 0;
}
