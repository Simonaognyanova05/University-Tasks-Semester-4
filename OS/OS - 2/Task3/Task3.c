#include <stdio.h>
#include <stdlib.h>

int* find(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) { 
            return &arr[i];
        }
    }
    return NULL; 
}

int main() {
    int numberOfRead, x;

    printf("Input number of read: ");
    scanf_s("%d", &numberOfRead);

    int* arr = (int*)malloc(numberOfRead * sizeof(int));
    if (arr == NULL) return 1;

    printf("Input %d numbers:\n", numberOfRead);
    for (int i = 0; i < numberOfRead; i++) {
        scanf_s("%d", &arr[i]);
    }

    printf("Input searched number: ");
    scanf_s("%d", &x);

    int* foundX = find(arr, numberOfRead, x);

    if (foundX != NULL) {
        int position = (int)(foundX - arr);
        printf("Намерено: %d на позиция (индекс): %d\n", *foundX, position);
        printf("Адрес в паметта: %p\n", (void*)foundX);
    }
    else {
        printf("Числото не е намерено.\n");
    }

    free(arr); 
    return 0;
}