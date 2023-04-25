#include <stdio.h>
#include <stdlib.h>

int main(void) {


  long double n = 10000;
  long double my_result = 0;
  long double *fatorial;
  fatorial = (long double*)calloc(n, sizeof(long double));

  for(int i =0; i<n; i++){

    
    if(i >= 1) fatorial[i] = fatorial[i-1]*i;

    
    else {
      fatorial[i] = 1;
    }


    
    my_result  = my_result + (1/fatorial[i]);
  }

  printf("\n%.62Lf\n", my_result);
  free(fatorial);
  return 0;
}
