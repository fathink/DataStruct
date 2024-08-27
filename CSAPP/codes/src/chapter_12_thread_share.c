/*
 第十二章： 并发编程
 
 测试多线程内存共享

*/

#include "../include/csapp.h"

#define N 2

void * thread_task(void *vargp);

char ** PTR; //全局指针，不同线程均能通过该指针间接访问到主线程栈中的数据

int main(int args, char * argv[])
{
    long i;
    pthread_t tid;

    char *msgs[N] = {"hello from foo","hello from bar"};

    PTR = msgs;

    for(i=0;i<N; i++)
        Pthread_create(&tid, NULL, thread_task, (void *) i);

    Pthread_exit(NULL);

    return 0;
}

void * thread_task(void * vargp)
{
    long my_id = (long) vargp;
    static int cnt = 0;  //cnt是全局变量，不同线程是共享的，A线程增加后会影响B线程
    printf("thread_id=%d\n", pthread_self());
    printf("task_id=[%ld]: %s, cnt=%d\n", my_id, PTR[my_id], ++cnt);

    return NULL;
}