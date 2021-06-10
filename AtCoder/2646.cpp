#include <stdio.h>

int main () {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int max = (a > b) ? a : b;
	max = (max > c) ? max : c;
	
	int res = a + b + c - max;
	printf("%d\n", res);
	return 0;
}
