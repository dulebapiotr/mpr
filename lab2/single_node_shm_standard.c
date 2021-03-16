#include "definitions.h"


double sender(int size) {
    char *buff = malloc(size);
    int i;
    double start = MPI_Wtime();
    for (i = 0; i < N; i++) {
        MPI_Send(buff, size, MPI_BYTE, RECEIVER, 0, MPI_COMM_WORLD);
        MPI_Recv(buff, size, MPI_BYTE, RECEIVER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    return MPI_Wtime() - start;
}

void receive(int size) {
    char *buff = malloc(size);
    int i;
    for (i = 0; i < N; i++) {
        MPI_Recv(buff, size, MPI_BYTE, SENDER, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(buff, size, MPI_BYTE, SENDER, 0, MPI_COMM_WORLD);
    }
}

void perform_tests(int rank){
    int message_size;
    for(message_size = MIN_MESSAGE_SIZE, message_size <= MAX_MESSAGE_SIZE, message_size *= MESSAGE_SIZE_INCREMENT_FACTOR){
        if(rank == SENDER){
            double test_time = send(message_size);
            printf("%f", test_time);
        } else if(rank == RECEIVER){
            receive(message_size);
        }
    }

}


int main(int argc, char *argv[]){
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    perform_tests(rank);

    MPI_Finalize();
    return 0;
}