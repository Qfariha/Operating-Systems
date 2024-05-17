#include<stdio.h>
#include<stdlib.h>  //malloc, exit
#include<sys/types.h>  //pid_t
#include<sys/wait.h>
#include<unistd.h> //fork, exec, sleep

int main() {
    pid_t pid1 = fork(); // Creating child
    
    if (pid1 == 0) {
        pid_t pid2 = fork(); // Creating grandchild
        
        if (pid2 == 0) {
            
            printf("I am grandchild\n");
        } else {
            
            wait(NULL); // child process waiting
            printf("I am child\n");
        }
    } else {
       
        wait(NULL); // parent process waiting
        printf("I am parent\n");
    }

    return 0;
}


