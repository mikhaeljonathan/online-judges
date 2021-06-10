#include <stdio.h>

int main () {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int res = a + b + c;
		
		int max = (a > b) ? a : b;
		max = (max > c) ? max : c;
		
		int min = (a < b) ? a : b;
		min = (min < c) ? min : c;
		
		res -= max + min;
		printf("Case %d: %d\n", i, res);
	}
	return 0;
}
