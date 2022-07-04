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


int main(){
    printf("Hello world\n");
    int *a;
    int b = 4;
    
    int t = 5;
    a = &t;

    int c = add(*a,b);
    printf("a=%d(%p),b=%d(%p),c=%d\n",*a,a,b,&b,c);

    c = add_new(a,&b);
    printf("a=%d(%p),b=%d(%p),c=%d\n",*a,a,b,&b,c);
    


    return 0;
}
