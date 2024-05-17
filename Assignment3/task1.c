#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //STDIN_FILENO
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h> //strcmp
#include <fcntl.h>
#include <sys/wait.h>


struct shared {
    char sel[100];
    int b;
};

int main() {
    int sm_id;
    struct shared *s_m, shared_data;
    pid_t pid;
    int fd[2];
    
 
    sm_id=shmget((key_t)101,1024,0666|IPC_CREAT); //shmget=>Creating shared memory segment


    s_m=shmat(sm_id,NULL,0); //shmat=> Attaching shared memory segment
    
  
    int pipe_1 = pipe(fd);
  

    printf("Provide Your Input From Given Options:\n");
    printf("1. Type a to Add Money\n");
    printf("2. Type w to Withdraw Money\n");
    printf("3. Type c to Check Balance\n");

  
    read(STDIN_FILENO, shared_data.sel, sizeof(shared_data.sel)); //STDIN_FILENO=> file descriptor for standard input device
    printf("Your selection: %c\n", shared_data.sel[0]); //Accessing sel from struct (like class variable)

    shared_data.b = 1000;

    pid = fork();

  
    if (pid == 0) { // Child process 

        int new;
        if (strcmp(shared_data.sel, "a\n") == 0) {  //strcmp=comparing two strings,0=equal
            printf("Enter amount to be added:\n");
            scanf("%d", &new);
            if (new > 0) {
                shared_data.b += new;
                printf("Balance added successfully\n");
                printf("Updated balance after addition:\n%d\n", shared_data.b);
            } else {
                printf("Adding failed, Invalid amount\n");
            }
        } else if (strcmp(shared_data.sel, "w\n") == 0) {
            printf("Enter amount to be withdrawn:\n");
            scanf("%d", &new);
            if (new > 0 && new <= shared_data.b) {
                shared_data.b -= new;
                printf("Balance withdrawn successfully\n");
                printf("Updated balance after withdrawal:\n%d\n", shared_data.b);
            } else {
                printf("Withdrawal failed, Invalid amount\n");
            }
        } else if (strcmp(shared_data.sel, "c\n") == 0) {
            printf("Your current balance is: %d\n", shared_data.b);
        } else {
            printf("Invalid selection\n");
        }

        
        write(fd[1], "Thank you for using", sizeof("Thank you for using"));
        close(fd[0]); 

        
    } else { // Parent process
        close(fd[1]); //closing the writing end of pipe

        char arr[100];
        read(fd[0], arr, sizeof(arr)); //reading from the pipe and storing in arr
        printf("%s\n", arr);
        close(fd[0]);
        wait(NULL); //Parent process waiting

        
        shmctl(sm_id, IPC_RMID, NULL); //removing shared memory 
    }

    return 0;
}

