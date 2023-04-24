#include <math.h>
#include <stdio.h>
#include <omp.h>

double f(double x) {
    return exp(x);
}

double Trap(double a, double b, int n) {
    double h = (b-a)/n;
    double local_a, local_b, my_result = 0.0;
    int i, local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
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
    double a = 1.0;
    double b = 704;
    double n = 2.0;
    double global_result = 0.0;
    int thread_count = 2;

    #pragma omp parallel num_threads(thread_count)
    {
        double my_result = 0.0;
        my_result = Trap(a, b, n);

        #pragma omp critical
        global_result += my_result;
    }

    //printf("\n%f\n\n", global_result);
    return 0;
}
