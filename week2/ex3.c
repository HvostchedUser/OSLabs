#include <stdio.h>
#include <stdlib.h>

void plotUpArrow(int n){
  for(int i=0; i<n; i++){
    for(int j=0;j<(n-i);j++){
      printf(" ");
    }
    for(int j=0;j<i*2-1;j++){
      printf("*");
    }
    printf("\n");
  }
}
void plotSquare(int n){
  for(int i=0; i<n; i++){
    for(int j=0;j<n;j++){
      printf("*");
    }
    printf("\n");
  }
}
void plotRightArrow(int n){
  for(int i=0; i<n; i++){
    for(int j=0;i<n/2?j<i:j<n-i;j++){
      printf("*");
    }
    printf("\n");
  }
}
void plotSemiArrow(int n){
  for(int i=0; i<n; i++){
    for(int j=0;j<i;j++){
      printf("*");
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]){
  plotUpArrow(atoi(argv[1])+1);
  return 0;
}
