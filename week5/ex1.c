#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void* threadFun(void* i) {
  int a = *((int *) i);
  printf(">>Hello from threadFun%d\n", a);
  pthread_exit(NULL);
}

int main () {
  pthread_t thread;
  for (int i=0;i<10;i++){
    int *arg = malloc(sizeof(*arg));
    if ( arg == NULL ) {
        printf("CANNOT PASS DATA\n");
      return 1;
    }

    *arg = i;
    if(pthread_create (&thread, NULL, threadFun, arg)){

      printf("CANNOT CREATE");
      pthread_exit (NULL);
      return 1;
    }else{
      printf("THREAD CREATED");
    }
  }
  pthread_exit (NULL);
  return 0;
}
