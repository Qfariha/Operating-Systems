#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    pid_t pid = fork();

    if (pid == 0) {  // Child process
        char *sorted_arr[argc + 1];
        sorted_arr[0] = "./sort";
        for (int i = 1; i < argc; i++) {
            sorted_arr[i] = argv[i];
        }
        sorted_arr[argc] = NULL;  

       
        execv("./sort", sorted_arr);  // Execute the sorting program
        
        
    } else {  
        wait(NULL);  // Parent waiting

            char *oddeven_arr[argc + 1];
            oddeven_arr[0] = "./oddeven";
            for (int i = 1; i < argc; i++) {
                oddeven_arr[i] = argv[i];
            }
            oddeven_arr[argc] = NULL; 

            // Execute the oddeven program
            execv("./oddeven", oddeven_arr);
        
    }

    return 0;
}



