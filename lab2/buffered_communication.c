
#include "definitions.h"

double sender_buffered(int size) {
    char *buff = malloc(size);
    int i;
    double start = MPI_Wtime();
    for (i = 0; i < N; i++) {
        MPI_Bsend(buff, size, MPI_BYTE, RECEIVER, 0, MPI_COMM_WORLD);
        MPI_Recv(buff, size, MPI_BYTE, RECEIVER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    return MPI_Wtime() - start;
}

void receiver_buffered(int size) {
    char *buff = malloc(size);
    int i;
    for (i = 0; i < N; i++) {
        MPI_Recv(buff, size, MPI_BYTE, SENDER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Bsend(buff, size, MPI_BYTE, SENDER, 0, MPI_COMM_WORLD);
    }
}

void test_buffered(int rank) {
    int size;
    for (size = 1; size <= MAX_MESSAGE_SIZE; size *=2) {
        if (rank == SENDER) {
            double time = sender_buffered(size);
//            printf("%f\n", time/N);
            printf("%f\n", N*size/(64*1024*time));
        } else if (rank == RECEIVER) {
            receiver_buffered(size);
        }
    }
}


int main(int argc, char *argv[]) {

    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Buffer_attach(malloc(MAX_MESSAGE_SIZE), MAX_MESSAGE_SIZE);
    test_buffered(rank);

    MPI_Finalize();
    return 0;
}