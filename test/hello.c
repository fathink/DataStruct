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

    int z=square(3+1);
    printf("d=%d\n",z);


    printf("*p=%c,p=%p,&p=%p\n",*p, p,&p);
    chang_c(&p);
    printf("*p=%c,p=%p,&p=%p\n",*p, p,&p);

    return 0;
}
