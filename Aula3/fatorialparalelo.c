#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
   int num;
   printf ("Enter the number: ");
   scanf ("%d", &num);

   int lim;

   int fd[2];

   if (pipe(fd) < 0) {
      perror("pipe");
      return -1;
   }

   if (num % 2 == 0) {
      lim = num / 2;
   } else {
      lim = (num / 2) + 1;
   }

   int i = 0;
   int x;
   while (i < lim) {
      if (fork() == 0) { // filho
         int part1 = num - 2 * i;
         int part2 = num - 2 * i - 1;
         x = part1 * part2;

         if (part1 == 0 || part2 == 0) {
            x = 1;
         }

         printf("[filho] %d from [pai] %d: %d * %d = %d\n", getpid(), getppid(), part1, part2, x);

         
         close(fd[0]); 
         write(fd[1], &x, sizeof(x));
         close(fd[1]); 

         exit(0);
      }

      i = i + 1;
   }

  
   for (int i = 0; i < lim; i++) {
      wait(NULL);
   }

  
   int result = 1;
   int temp;
   close(fd[1]); 
   while (read(fd[0], &temp, sizeof(temp)) > 0) { 
      result *= temp;
   }
   close(fd[0]); 

   printf("\n\nresultado: %d! = %d\n", num, result);

   return 0;
}
