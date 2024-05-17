#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TEXT 6

struct msg {
    long int type;
    char txt[MAX_TEXT];
};

int main() {
    pid_t pid_1,pid_2; 
    int msg_id;
    struct msg text_msg; //text_msg.txt,text_msg.type from struct

  
    msg_id = msgget((key_t)51, 0666 | IPC_CREAT);


    //Login process
    
    printf("Please enter the workspace name:\n");
	char workspace[MAX_TEXT];
	scanf("%s", workspace);
	if (strcmp(workspace, "cse321") != 0) {
    	printf("Invalid workspace name\n");
    	exit(EXIT_FAILURE);
	}
    
    text_msg.type = 5; //workspace=> name=> OTP generator
    msgsnd(msg_id, (void *)&text_msg, MAX_TEXT, 0);
    
    strcpy(text_msg.txt, workspace); //writing the name in txt
    printf("Workspace name sent to otp generator from log in: %s\n", text_msg.txt);
    
    
    
    
    pid_1 = fork(); //For OTP generator process
   
    if (pid_1 == 0) { 
        

    
        msgrcv(msg_id, (void *)&text_msg, MAX_TEXT, 5, 0); //Receiving workspace name(txt) from login with same message type
          
        printf("OTP generator received workspace name from log in: %s\n", text_msg.txt);


      
        int otp = getpid();
        sprintf(text_msg.txt, "%d", otp);
        text_msg.type = 7; 
        msgsnd(msg_id, (void *)&text_msg, MAX_TEXT, 0); // OTP generator=> OTP=> Login
        
        printf("OTP sent to log in from OTP generator: %s\n", text_msg.txt);

        
        text_msg.type = 6; 
        msgsnd(msg_id, (void *)&text_msg, MAX_TEXT, 0); // OTP generator=> OTP=> mail
        
        printf("OTP sent to mail from OTP generator: %s\n", text_msg.txt);

        exit(EXIT_SUCCESS);
    }

    
    pid_2 = fork(); // For the mail process
  
    
    if (pid_2== 0) { 
        

       
        msgrcv(msg_id, (void *)&text_msg, MAX_TEXT, 6, 0); 
        printf("Mail received OTP from OTP generator: %s\n", text_msg.txt);

        
        text_msg.type = 8; 
        msgsnd(msg_id, (void *)&text_msg, MAX_TEXT, 0); //Mail=> OTP => login
        printf("OTP sent to log in from mail: %s\n", text_msg.txt);

        exit(EXIT_SUCCESS);
    }

    
   
    wait(NULL); //For login process

    
    msgrcv(msg_id, (void *)&text_msg, MAX_TEXT, 7, 0); // From OTP generator

    msgrcv(msg_id, (void *)&text_msg, MAX_TEXT, 8, 0); //From mail
 
    printf("Log in received OTP from OTP generator: %s\n", text_msg.txt);
    printf("Log in received OTP from mail: %s\n", text_msg.txt);
    
       
    char otp_gen[MAX_TEXT];
    strcpy(otp_gen, text_msg.txt);
    
    char otp_mail[MAX_TEXT];
    strcpy(otp_mail, text_msg.txt);

 
    if (strcmp(otp_gen, otp_mail) == 0) {
        printf("OTP Verified\n");
    } else {
        printf("OTP Incorrect\n");
    }

    msgctl(msg_id, IPC_RMID, 0);

    return 0;
}


