#include<stdio.h>
int perfect_num(int num);

int main() {
    int start, end;
    scanf("%d", &start);
    scanf("%d", &end);
    
    int idx = start;
    while (idx <= end) {
        if (perfect_num(idx)) {
            printf("%d\n", idx);
        }
        idx++;
    }

    return 0;
}

int perfect_num(int num) {
    int j = 1, total = 0;
    while (j < num) {
        if (num % j == 0) {  //if num is divisible by j
            total += j;
        }
        j++;
    }
    return total == num;
}

