#include <math.h>
#include <stdio.h>

double f(double x){ //funcao que vai gerar onde vamos ter os trapezios
	return exp(x); // retorna o exponencial ( número de Euler ) e (ou 2,71828) elevado ao argumento fornecido.
}


int main(){

  double a,b,n;

  a = 1; // ponto inicial
  b = 704; // ponto final 
  n = 2; // numero de trapezios / divisoes feitas na função
  

  
  
  double h = (b-a)/n;
  double approx = (f(a) + f(b))/2;
  double x_i;
  for(int i = 1; i<=n-1;i++){
    x_i = a + i*h;
    approx += f(x_i);
  }
  approx = h*approx;
  
  //printf("\n%lf\n\n", approx);
  return 0;
}
