#include <stdio.h>
#include <stdlib.h>

int* filter_even(int* arr, int n, int* count) {
	int even_count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			even_count++;
		}
	}

	*count = even_count;
	int* even_arr = (int*)malloc(even_count * sizeof(int));

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			even_arr[j] = arr[i];
			j++;
		}
	}

	return even_arr;
}

int main() {
	int n = 4;
	int arr[] = {1, 2, 3, 4};
	int countEven = 0;

	int* evens = filter_even(arr, n, &countEven);

	for (int i = 0; i < countEven; i++) {
		printf("%d \n", evens[i]);
	}

	if (evens != NULL) {
		free(evens);
	}
	return 0;
}