#include <stdio.h>
#include <stdlib.h>


int main() {
    int* N;
    scanf("%d", N);
    int *vals = malloc(*N*sizeof(int));
    for (int i = 0; i < *N; ++i) {
        vals[i] = i;
    }
    for (int i = 0; i < *N; ++i) {
        printf("%d ", vals[i]);
    }
    printf("\n");
    free(vals);   
}
