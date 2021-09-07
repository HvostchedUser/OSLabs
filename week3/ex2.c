#include <stdio.h>

void bubble_sort(int *arrptr, int len)
{
    for(int i = 0;i<len-1;i++)
        for(int j = 0;j<len-1;j++)
        {
            if(arrptr[j]>arrptr[j+1])
            {
                int t = arrptr[j+1];
                arrptr[j+1] = arrptr[j];
                arrptr[j] = t;
            }
        }
}

int main()
{
    int arrayTest[6] = {2,4,1,6,8,3};
    bubble_sort(arrayTest,6);
    for(int i = 0;i<6;i++)
        printf("%d ",arrayTest[i]);
}
