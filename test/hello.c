#include <stdio.h>

int add(int a,int b){
    return a+b;
}


int add_new(int *a,int *b)
{
    *a += 1;
    
    int out = (*a) + (*b);
    return out;

}

void chang_c(char **p)
{
    char c='z';
    printf("p=%p,*p=%p\n",p,*p);
    *p=&c;
    printf("p=%p,*p=%p,&c=%p\n",p,*p,&c);
}

int main(){
    printf("\n");
    


    char c='w';
    char *p;
    p = &c;  //p指向c

    typedef enum {A,B} POINT;
    POINT po=B;
    printf("%d\n",po);

    return 0;
}
