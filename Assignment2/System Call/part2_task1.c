#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv[]){
    int num;
    int fd;
    char inpstr[100];
    num=read(0,inpstr,100);  //after reading input, storing in inpstr,returning the byte size of input
    fd = open(argv[1],O_CREAT | O_WRONLY, 0600); //create and write only
    if (fd < 0) {
         perror("File open failed");
         exit(1);
     }
 
    int str_to_num=atoi(inpstr) ;                               
    while(str_to_num!=-1){    //atoi=> str_to_num
        write(fd,inpstr,num);
        num=read(0,inpstr,100);
        str_to_num=atoi(inpstr);
    }
    return 0;
    }  


