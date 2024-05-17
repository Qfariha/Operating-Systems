#include <stdio.h>
#include <string.h>
#include <stdbool.h>



bool is_substring(char *new_domain, char *email) {
   int em_len = strlen(email);
   int newdom_len = strlen(new_domain);
   for (int i = 0; i < em_len; i++) {
     
       if (email[i] == '@') { //untill this condition is true, i increment
          
           for (int j = 0; j < newdom_len; j++) {
               if (new_domain[j] != email[i+j]) { // outer if true, checking with incremented i value
                   return false;
               }
           }
          
           return true;
       }
   }
  
}

 

int main(void)
{
  char em[256];
  char newdom[]="@sheba.xyz";
  printf("enter email: ");
  scanf("%s",em);
  if (is_substring(newdom,em))
    printf("Email address is okay.\n");
  else
    printf("Email address is outdated.\n");
  return 0;
}
