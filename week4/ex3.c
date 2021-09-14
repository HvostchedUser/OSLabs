#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
        char input[1024] = "";
        while(1){
            printf("sample> ");
            scanf("%s", input);
            system(input);
        }
        return 0;
}
