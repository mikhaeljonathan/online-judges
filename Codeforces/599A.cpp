#include <stdio.h>

int min (int a, int b){
	if (a < b) return a;
	return b;	
}

int main () {
	int d1, d2, d3;
	scanf("%d %d %d", &d1, &d2, &d3);
	int res = min(2 * (d1 + d2), d1 + d2 + d3);
	res = min(res, 2 * (min(d1, d2) + d3));
	printf("%d\n", res);
	return 0;
}
