#include <stdio.h>

int main () {
	int n;
	scanf("%d", &n);
	int total = 0;
	for (int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		total += a;
	}
	printf("%d\n", total);
	return 0;
}
