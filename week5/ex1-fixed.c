#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int lock=0;
void* threadFun(void* i) {
  int a = *((int *) i);
  printf(">>Hello from threadFun%d\n", a);
  printf("lock: %d\n", lock);
  lock=0;
  printf("lock: %d\n", lock);
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
    lock=1;
    if(pthread_create (&thread, NULL, threadFun, arg)){

      printf("CANNOT CREATE");
      pthread_exit (NULL);
      return 1;
    }else{
      printf("THREAD CREATED");
    }
    while(lock==1){

    }
  }
  pthread_exit (NULL);
  return 0;
}
