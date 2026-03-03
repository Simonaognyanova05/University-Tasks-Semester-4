#include <stdio.h>

int main() {

	int num1, num2, temp;

	int *a = &num1;
	int *b = &num2;

	scanf_s("%d", a);
	scanf_s("%d", b);

	temp = *a;
	*a = *b;
	*b = temp;

	printf("a = %d", *a);
	printf("b = %d", *b);

	return 0;
}