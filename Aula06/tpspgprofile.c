#include <math.h>
#include <stdio.h>


double f(double x) {
    return exp(x);
}

double Trap(double a, double b, int n, int thread_count, int my_rank) {
    double h = (b-a)/n;
    double local_a, local_b, my_result = 0.0;
    int i, local_n;
    local_n = n/thread_count;
    local_a = a + my_rank*local_n*h;
    local_b = local_a + local_n*h;
    my_result = (f(local_a) + f(local_b))/2;
    for (i = 1; i <= local_n-1; i++) {
        double x = local_a + i*h;
        my_result += f(x);
    }
    my_result *= h;
    return my_result;
}

int main() {
    long double a = 1.0;
    long  double b = 1000000;
    long double n = 10.0;
    long double global_result = 0.0;
    int thread_count = 2;
    
    
    for(int i = 1; i<= thread_count; i++)
    {
       long  double my_result = 0.0;
        my_result = Trap(a, b, n, thread_count, i);

        global_result += my_result;
    }

    //printf("\n%f\n\n", global_result);
    return 0;
}
