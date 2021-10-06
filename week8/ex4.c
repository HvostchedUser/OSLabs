#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sys/resource.h>

int main() {
  size_t sz=80000000;
  struct rusage usage;
    for (int i = 0; i < 10; i++) {
        printf("MEMORY USAGE:\n");
        getrusage(RUSAGE_SELF,&usage);
        printf("%ld\n", usage.ru_maxrss);
        void *mem = malloc(sz);
        memset(mem, 0, sz);
        sleep(1);
    }
    return 0;
}
