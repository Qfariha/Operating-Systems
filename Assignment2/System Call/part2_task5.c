#include<stdio.h>
#include<stdlib.h>  //malloc, exit
#include<sys/types.h>  //pid_t
#include<sys/wait.h>
#include<unistd.h> //fork, exec, sleep
#include <pthread.h>

int main() {
    pid_t pid1 = fork(); // Creating child

    if (pid1 == 0) {
       
        printf("Child process pid: %d\n", getpid());

        for (int i = 0; i <3; i++) {
            pid_t pid2 = fork(); // Creating grandchild

            if (pid2 == 0) {
                
                printf("Grandchild process pid: %d\n", getpid());
                break; 
            }
        }
    } else {
        
        wait(NULL); // Parent process waiting
        printf("Parent process pid: %d\n", getpid());
    }

    return 0;
}

