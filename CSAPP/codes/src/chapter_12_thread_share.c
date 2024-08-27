/*
 * 第十二章： 并发编程
 *
 * 
 * 
 * 
*/

#include "../include/csapp.h"

#define N 2

void * thread(void *vargp);

char ** ptr; //全局指针

int main(int args, char * argv[])
{
    int i;
    pthread_t tid;

    char *msgs[N] = {"hello from foo","hello from bar"};

    ptr = msgs;
    printf("ok\n");

    return 0;
}

void * thread(void * vargp){

    return NULL;
}