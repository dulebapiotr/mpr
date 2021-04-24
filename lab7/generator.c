# include <omp.h>
#include <time.h>
#include <stdlib.h>


void main(int argc, char *argv[]) {
    srand(time(NULL)); 

    unsigned long long size = strtoull(argv[1], NULL, 0);
    int chunk = atoi(argv[2]);

    int rand_array[size];
    unsigned long long i;

    double start = omp_get_wtime();
    #pragma omp for schedule(static, chunk)
    for(i=0; i<size; i++){
        rand_array[i] = rand();
    }
    double stop = omp_get_wtime();
    printf("Time: %lf\n", stop - start);
    printf("Size: %d\n", size);
    printf("Chunk: %d\n", chunk);

}