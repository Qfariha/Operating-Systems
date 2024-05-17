#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *word);

int main(void)
{
  char word[256];
  printf("Word please: ");
  scanf("%s",word);
  

  if (is_palindrome(word)==true)
    {printf("Palindrome\n");
  }else
    {printf("Not a palindrome\n");
  return 0;}


}
bool is_palindrome(char *word) {
    	
    char *start = word;
    char *end = word+strlen(word)-1;

    while (*start < *end) {

        if (*start != *end) {
            return false;
        }
        *start++;
        *end--;
    }

    return true;
}

