#include <stdio.h>

int main (){
	int n, k;
	scanf("%d %d", &n, &k);
	while (k--) n = (n % 10 == 0) ? n / 10 : n - 1;
	printf("%d\n", n);
	return 0;
}
