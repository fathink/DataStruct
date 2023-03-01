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


typedef struct _Edge
{
    int begin;
    int end;
    int weight;
} Edge;

void sort(Edge *edge){
    int i,j;
    Edge e;
    
    for(i=0;i<10-1;i++)
        for(j=0;j<10-1-i;j++){
            if(edge[j].weight<edge[j+1].weight){
                e = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = e;       
            }
        }
}

int main(){
    printf("\n");
    int i,j;


    int a[5]={1,2,3,4,5};
    printf("%p,%p\n",a,a+1);
    printf("%p\n",&a+1);
    printf("==%d\n",*(a+1));
    
    
    char c='w';
    char *p;
    p = &c;  //p指向c

    char r='r';
    char *z;
    z = &r;  //z指向r
    // *z='b';
    // *z = *p;
    
    *z = *p;
    printf("point_p=%p#%c,point_z=%p#%c\n",p,*p,z,*z);
    printf("%p\n",&p);


    // typedef enum {A,B} POINT;
    // POINT po=B;
    // printf("%d\n",po);

    return 0;
}

