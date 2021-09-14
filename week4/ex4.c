#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//system call can run bash commands with arguments and background proccesses
int main(){
        char input[1024] = "";
        while(1){
            printf("sample> ");
            scanf("%s", input);
            system(input);
        }
        return 0;
}
