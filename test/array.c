/*
    数组与指针
*/

#include <stdio.h>

#define MAXSIZE 10


void sort(int *p[],int length)
{
    int i,j,k;
    for(i=0;i<length-1;i++)
    {
        for(j=0;j<length-1;j++)
        {
            if(*p[j] > *p[j+1])
            {
                k=*p[j];
                *p[j]=*p[j+1];
                *p[j+1] = k;

            }
        }
    }
    
}

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

    printf("\nArrays=");
    for(i=0;i<MAXSIZE;i++)
    {
        printf(" %d",a[i]);
    }
    printf("\n");

    // 测试指针数组
    int a0=11;
    int a1=30;
    int a2=35;
    int a3=120;
    int a4=89;
    int *pa[5];
    pa[0] = &a0;
    pa[1] = &a1;
    pa[2] = &a2;
    pa[3] = &a3;
    pa[4] = &a4;

    //排序前
    for(i=0;i<5;i++)
    {
        printf("idx=%d,address=%p,value=%d\n",i,pa[i],*pa[i]);
    }
    printf("\n");

    sort(pa,5);

    //排序后
    for(i=0;i<5;i++)
    {
        printf("idx=%d,address=%p,value=%d\n",i,pa[i],*pa[i]);
    }


  
    

    

    return 0;
}

