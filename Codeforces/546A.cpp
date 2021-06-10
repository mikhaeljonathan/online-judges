#include <stdio.h>

int main (){
	int k, n, w;
	scanf("%d %d %d", &k, &n, &w);
	w = w * (w + 1) / 2;
	printf("%d\n", (n < k * w) ? k * w - n : 0);
	return 0;
}
