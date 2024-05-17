#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp1, *fp2;
    fp1 = fopen("t2b_input.txt", "r");
   
    fp2 = fopen("t2b_output.txt", "wb");
 
    char in[256];
    fgets(in, sizeof(in), fp1);
    fclose(fp1);

    for (int i = 0; in[i] != '\0'; i++) {
        if (!(in[i] == ' ' && in[i + 1] == ' ')) {
            fputc(in[i], fp2);
        }
    }

    fclose(fp2);
    return 0;
}

