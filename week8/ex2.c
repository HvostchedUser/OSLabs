#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  size_t sz=80000000;
    for (int i = 0; i < 10; i++) {
        void *mem = malloc(sz);
        memset(mem, 0, sz);
        sleep(1);
    }
    return 0;
}
//si and so are zeros, nothing happens to these values when I run the program
//if I allocate more memory instead, the system starts to use swap and si snd so values start to increase
