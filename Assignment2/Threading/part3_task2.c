#include<stdio.h>
#include<stdlib.h>  //malloc, exit
#include<sys/types.h>  //pid_t
#include<sys/wait.h>
#include<unistd.h> //fork, exec, sleep

#include <pthread.h>
void *funcThread(void *arg);

int main() {
    pthread_t t1, t2, t3, t4, t5;

    
    pthread_create(&t1, NULL, funcThread, (void *)0);  // 0= arguement passed in funcThread
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, funcThread, (void *)1);
    pthread_join(t2, NULL);
    pthread_create(&t3, NULL, funcThread, (void *)2);
    pthread_join(t3, NULL);
    pthread_create(&t4, NULL, funcThread, (void *)3);
    pthread_join(t4, NULL);
    pthread_create(&t5, NULL, funcThread, (void *)4);
    pthread_join(t5, NULL);

    return 0;
}

void *funcThread(void *arg) {
    int thread_num = (int)arg;
    int start = thread_num*5+1;

    for (int i=start; i<start+5; i++) {
        printf("Thread %d prints %d\n", thread_num, i);
        sleep(1);
    }

}

