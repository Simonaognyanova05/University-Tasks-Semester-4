#include <stdio.h>

int main() {
	int a, b;
	scanf_s("%d", &a);
	scanf_s("%d", &b);

	
	printf("a = %p, b = %p", &a, &b);
}