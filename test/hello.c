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
    
    for(i=0;i<10;i++)
        for(j=0;j<10-1;j++){
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

    Edge edge[10];
    for(i=0;i<10;i++){
        edge[i].begin=i;
        edge[i].end=i+1;
        edge[i].weight=i*i;
    }
    for(i=0;i<10;i++){
        printf("(%d,%d) %d\n",edge[i].begin,edge[i].end,edge[i].weight);
    }

    sort(edge);

    printf("\nsorted:\n");
    for(i=0;i<10;i++){
        printf("(%d,%d) %d\n",edge[i].begin,edge[i].end,edge[i].weight);
    }
    


    char c='w';
    char *p;
    p = &c;  //p指向c

    typedef enum {A,B} POINT;
    POINT po=B;
    printf("%d\n",po);

    return 0;
}

