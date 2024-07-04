# include<stdio.h>
# include<pthread.h>

typedef struct lock_t
{
    int flag;
}lock_t;

//测试并设置指令模拟
int TestAndSet(int *old_ptr, int new){
    int old = *old_ptr;
    *old_ptr = new;
    return old;
}

//初始化锁
void init(lock_t *mutex){
    mutex->flag = 0;  //0表示没有线程占用锁，1表示有线程占用锁
}

//加锁
void lock(lock_t *mutex){
    while (TestAndSet(&mutex->flag,1) == 1)
    ; //spin-wait
}

//释放锁
void unlock(lock_t *mutex){
    mutex->flag = 0;
}


/**************测试锁******************/
int s = 0;
lock_t mutex;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *mythread(void *arg){
    printf("Thread=%s\n",(char *)arg);
    for(int i=0;i<10000;i++){
        // lock(&mutex);
        pthread_mutex_lock(&mtx);
        s = s+1;
        // unlock(&mutex);
        pthread_mutex_unlock(&mtx);
    }
    printf("Thread=%s Done\n",(char *)arg);
    return NULL;
}

int main(int argc, char *argv[]){

    int rc;
    pthread_t p1,p2;

    init(&mutex);
    rc = pthread_create(&p1, NULL, mythread, "A");
    rc = pthread_create(&p2, NULL, mythread, "B");

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("s=%d\n",s);

    return 0;
}