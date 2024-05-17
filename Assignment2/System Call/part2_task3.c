#include<stdio.h>
#include<stdlib.h>  //malloc, exit
#include<sys/types.h>  //pid_t
#include<sys/wait.h>
#include<unistd.h> //fork, exec, sleep

int main() {
    int a, b, c;
    int t_process = 1; //parent process

    a = fork();
    t_process+= 1;
    b = fork();
    t_process+= 1;
    c = fork();
    t_process+= 1;

    if (a == 0) {
        if (getpid() % 2 != 0) {
            fork();
            t_process+=1;
        }
    } else if (b == 0) {
        if (getpid() % 2 != 0) {
            fork();
            t_process+=1;
        }
    } else if (c == 0) {
        if (getpid() % 2 != 0) {
            fork();
            t_process+=1;
        }
    } 
    else{
    printf("Total number of processes: %d\n", t_process);
	}

    return 0;
}

