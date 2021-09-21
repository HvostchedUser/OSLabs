#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 5

int iter = 0;
int buffer[SIZE];
int waitcons=0;
int waitprod=0;

void* producer(void* arg) {
    while (1) {
        while (waitprod);
        while (iter>=SIZE){
            waitcons=0;
            waitprod=1;
            continue;
        }
        buffer[iter] = rand();
        iter++;
    }
}

void* consumer(void* arg) {
    while (1) {
        while (waitcons);
        if (iter<0){
            waitcons=1;
            waitprod=0;
            continue;
        }
        buffer[iter] = rand();
        iter--;
    }
}

int main() {
    pthread_t tproducer, tconsumer;
    pthread_create(&tconsumer, NULL, consumer, NULL);
    pthread_create(&tproducer, NULL, consumer, NULL);
    pthread_join(tproducer, NULL);
    pthread_join(tconsumer, NULL);
    return 0;
}
