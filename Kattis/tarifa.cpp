#include<stdio.h>

int main () {
	int x, n;
	scanf("%d", &x);
	scanf("%d", &n);
	long res = x * n;
	for (int a = 1; a <= n; a++){
		int p;
		scanf("%d", &p);
		res -= p;
	}
	res += x;
	printf("%d\n", res);
	return 0;
}
