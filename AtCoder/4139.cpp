#include <stdio.h>

int main () {
	int a, b;
	scanf("%d %d", &a, &b);
	int res = (a + b > a - b) ? a + b : a - b;
	res = (res > a * b) ? res : a * b;
	
	printf("%d\n", res);
	return 0;
}
