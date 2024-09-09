/*
 第十二章： 并发编程
 
 线程同步错误，本实例创建两个线程，每个线程都对共享计数变量cnt加1；

*/

#include "../include/csapp.h"


void * thread_task(void *vargp);

volatile int cnt = 0; // 全局的计数器

int main(int args, char * argv[])
{
    long niters = 10000;

    pthread_t tid1, tid2;
   
    Pthread_create(&tid1, NULL, thread_task, &niters);
    Pthread_create(&tid2, NULL, thread_task, &niters);

    Pthread_join(tid1, NULL);
    Pthread_join(tid2, NULL);
    
    // 检查niters是否符合预期
    if (cnt != (2*niters))
        printf("ERROR\tcnt=%d\n", cnt);
    else
        printf("OK\tcnt=%d\n", cnt);

    return 0;
}

void * thread_task(void * vargp)
{
    long i, niters = *((long *) vargp);  //指针先强制转为long* 类型，然后再取值

    for(i=0; i<niters; i++)
        // 这里的自增操作实际分成三步，内存加载到寄存器，寄存器自增1，写回内存；
        // 无法预料cpu一定操作完整个流程
        cnt++;

    return NULL;
}