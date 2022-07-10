/*
    数组与指针
*/

#include <stdio.h>

#define MAXSIZE 10

int main()
{
    int i;
    int a[MAXSIZE];

    for(i=0;i<MAXSIZE;i++){
        a[i] = i+1;
    }

    int *pa1,*pa2;
    pa1 = &a[0];
    pa2 = a;  // pa2和pa1等价





    printf("Arrays=");
    for(i=0;i<MAXSIZE;i++)
    {
        printf(" %d",a[i]);
    }



    return 0;
}