#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int res = 0;
	for (int i = 1; i < n; i++) if (!(n % i)) res++;
	printf("%d\n", res);
	return 0;
}
