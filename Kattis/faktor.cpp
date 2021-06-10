#include <stdio.h>

int main () {
	int a, b;
	scanf("%d %d", &a, &b);
	b--;
	int res = a * b + 1;
	printf("%d\n", res);
	return 0;
}
