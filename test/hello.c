#include <stdio.h>

int add(int a,int b){
    return a+b;
}


int add_new(int *a,int *b)
{
    *a += 1;
    
    int out = (*a) + (*b);
    return *a+*b;

}


int main(){
    printf("Hello world\n");
    int a = 3;
    int b = 4;

    printf("a=%d,b=%d,out=%d\n",a,b,add(a,b));
    printf("a=%d,b=%d,out=%d\n",a,b,add_new(&a,&b));

    return 0;
}
