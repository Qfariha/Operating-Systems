#include<stdio.h>
#include<stdlib.h>  //malloc, exit
#include<sys/types.h>  //pid_t
#include<sys/wait.h>
#include<unistd.h> //fork, exec, sleep
#include <pthread.h>

void *funcThread(void *arg);

int main() {
    pthread_t t1, t2, t3, t4, t5;

    pthread_create(&t1, NULL, funcThread, (void *)1);  // 1= argument passed in funcThread
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, funcThread, (void *)2);
    pthread_join(t2, NULL);
    pthread_create(&t3, NULL, funcThread, (void *)3);
    pthread_join(t3, NULL);
    pthread_create(&t4, NULL, funcThread, (void *)4);
    pthread_join(t4, NULL);
    pthread_create(&t5, NULL, funcThread, (void *)5);
    pthread_join(t5, NULL);

    return 0;
}

void *funcThread(void *arg) {
    int thread_num = (int)arg;

    printf("Thread-%d running\n", thread_num);
   
    sleep(1);
    printf("Thread-%d closed\n", thread_num);


}

