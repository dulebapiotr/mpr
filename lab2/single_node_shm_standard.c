#include "definitions.h"

double sender(int msg_size) {
    char *buff = malloc(msg_size);
    int i;
    double start = MPI_Wtime();
    for (i = 0; i < N; i++) {
        MPI_Send(buff, size, MPI_BYTE, RECEIVER, 0, MPI_COMM_WORLD);
        MPI_Recv(buff, size, MPI_BYTE, RECEIVER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    return MPI_Wtime() - start;
}

void receiver(int msg_size) {
    char *buff = malloc(msg_size);
    int i;
    for (i = 0; i < N; i++) {
        MPI_Recv(buff, size, MPI_BYTE, SENDER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(buff, size, MPI_BYTE, SENDER, 0, MPI_COMM_WORLD);
    }
}

void test(int rank) {
    printf("N  msg_size  time \n");
    int msg_size;
    for (msg_size = 1; msg_size <= MAX__MESSAGE_SIZE; msg_size *= 2) {
        if (rank == SENDER) {
<<<<<<< HEAD
            double time = sender(size);
            printf("%.5f  ", N);
            printf("%.5f  ", size);
            printf("%.5f  ", time);
            printf("%.5f  ", N*size/time/1000000*2);
=======
            double time = sender(msg_size);
            printf("%d  ", N);
            printf("%d  ", msg_size);
            printf("%d  ", time);
>>>>>>> de0d752bb6989bc151dae99f5ee8bd7a52cbadaf
        } else if (rank == RECEIVER) {
            receiver(msg_size);
        }
    }
}

int main(int argc, char *argv[]) {

    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    test(rank);

    MPI_Finalize();
    return 0;
}