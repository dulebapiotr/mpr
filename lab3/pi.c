#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_inside(double x, double y) {
    if (x*x+y*y <= 1)
        return 1;
    else
        return 0;
}

unsigned long long get_points(unsigned long long n) {
    register unsigned long long i, in = 0;
    register double a, b;
    for (i = 0; i < n; i++) {
        a =  (double) rand() / RAND_MAX;
        b =  (double) rand() / RAND_MAX;
        in += is_inside(a, b);
    }
    return in;
}


int main(int argc, char *argv[]) {
    unsigned long long n = strtoull(argv[1], NULL, 0);
    srand(time(NULL));
    printf("n = %llu, π = %'.10Lf\n", n, (long double) get_points(n)/n);
}