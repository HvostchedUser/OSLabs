#include <stdio.h>
#include <string.h>
int main()
{
   char s[100];
   printf("write your text\n");
   gets(s);
   strrev(s);
   printf("reversed text: %s\n", s);
   return 0;
}
