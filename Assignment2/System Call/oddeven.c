#include <stdio.h>

void oddeven(int n) {
    if (n % 2 == 0) {
        printf("Number is even: %d\n", n);
    } else {
        printf("Number is odd: %d\n", n);
    }
}

int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        oddeven(num);
    }

    return 0;
}

