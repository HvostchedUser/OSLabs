#include<stdio.h>

void swap(int* a, int* b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
int main(){
  int a,b;
  printf("First number: ");
  scanf("%d",&a);
  printf("second number: ");
  scanf("%d",&b);
  printf("%d\n",a);
  printf("%d\n\n",b);
  swap(&a,&b);
  printf("%d\n",a);
  printf("%d\n",b);
}
