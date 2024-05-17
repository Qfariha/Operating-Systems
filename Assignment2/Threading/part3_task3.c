#include<stdio.h>
#include<stdlib.h>  //malloc, exit
#include<sys/types.h>  //pid_t
#include<sys/wait.h>
#include<unistd.h> //fork, exec, sleep

void *ascii(void *arg);

int main()
{
    pthread_t t1, t2, t3;
    char *n1 = "Quazi";
    char *n2 = "Fariha";
    char *n3 = "Fairooz";
    
    int *v1, *v2, *v3;

    pthread_create(&t1, NULL,ascii, (void *)n1);
    
    pthread_create(&t2, NULL,ascii, (void *)n2);
    
    pthread_create(&t3, NULL, ascii, (void *)n3);
    
    pthread_join(t1, (void **)&v1); // (void **)&v1)=>address where the exit status(return val of func) 
    pthread_join(t2, (void **)&v2);
    pthread_join(t3, (void **)&v3);

    if (*v1 == *v2 && *v1 == *v3)
    {
        printf("Youreka\n");
    }
    else if (*v1 == *v2 || *v1 == *v3 || *v2 == *v3)
    {
        printf("Miracle\n");
    }
    else
    {
        printf("Hasta la vista\n");
    }

    return 0;
}


void *ascii(void *arg)
{
    char *name = (char *)arg;
    int i = 0, total = 0;
    int *value = (int *)malloc(sizeof(int));  //malloc for memory allocation(*value=dynamically allocated memory for storing int values)
 
    for (int i = 0; name[i] != '\0'; i++) {
        total+= name[i];
  
    *value = total;
    return value;
}

}

