#include <stdio.h>

#include <stdlib.h>



int main() {

    printf("\n=== Dynamic Array ===\n");
    int n;
    printf("Inpunt n: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Elements: \n");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}