#include <stdio.h>

void sort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }   
        }
    }
}

int main(int argc, char *argv[]) {
    int size = argc - 1;
    int arr[argc-1];
    for(int i = 0; i < argc-1; i++) {
        arr[i] = atoi(argv[i+1]);
    }

    sort(arr, size);

    printf("Sorted array in descending order: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

