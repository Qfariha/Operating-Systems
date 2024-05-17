#include<stdio.h>
#include<ctype.h>




int checking_uppercase(char password[100]){  
    int i=0;
    while (password[i] != '\0'){ //checking till the end of password
       if (isupper(password[i])){
            return 1;  // upper_letter present
        }i++;      
    } return 0;  //else not present

}
int checking_digit(char var[100]){
    int i=0;
    while (var[i] != '\0'){
        if (isdigit(var[i])){
            return 1;
        }i++;
    

    } return 0;

}
int checking_lowercase(char password[100]){
    int i=0;
    while (password[i] != '\0'){
        if (islower(password[i])){
            return 1;
        }i++;
    

    } return 0;

}
int checking_specialchar(char password[100]){  //receiving in the parameter => password 
    int i=0;
    while (password[i] != '\0'){
        if (ispunct(password[i])){
            return 1;
        }i++;
    

    } return 0;
}

int main(void){
    int dig,up,low,sp;
    char str[100];  //array of size 100
    printf("Password please: ");
    scanf("%s", str);   // array already holds the location so not &str
    
    dig=checking_digit(str);
    up=checking_uppercase(str);
    low=checking_lowercase(str);
    sp=checking_specialchar(str);
    if(dig==1 && low==1 && up==1 && sp==1)
    {
        printf("OK ");
    } 
    else{
        if(low==0)
        {
            printf("Lowercase character missing.\n");
        } 
        if(up==0)
        {
            printf("Uppercase missing character missing.\n ");

        } 
        if(dig==0)
        {
            printf("Digit missing.\n");
        } 
        if(sp==0)
        {
            printf("Special character missing.\n");
        }
    }

    return 0;

}




