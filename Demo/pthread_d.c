// 对线程示例
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

void * my_thread(void *arg){
    printf("%s\n",(char *)arg);
    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t p1,p2;
    int rc;
    printf("main:begin\n");

    rc = pthread_create(&p1, NULL, my_thread, "Adjs");assert(rc==0);
    rc = pthread_create(&p2, NULL, my_thread, "Bnksd");assert(rc==0);

    //等待所有线程结束
    rc = pthread_join(p1, NULL);assert(rc==0);
    rc = pthread_join(p2, NULL);assert(rc==0);
    printf("main:end\n");
    return 0;
}