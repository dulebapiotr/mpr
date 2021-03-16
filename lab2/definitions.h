
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define MIN_MESSAGE_SIZE 1
#define MAX_MESSAGE_SIZE 100000
#define MESSAGE_SIZE_INCREMENT_FACTOR 100

#define TEST_ATTEMPTS = 1000

#define SENDER 0
#define RECEIVER 1
