#include <stdio.h>

int main (){
	int n, k;
	scanf("%d %d", &n, &k)	;
	int f[n], t[n];
	for (int i = 0; i < n; i++)	scanf("%d %d", &f[i], &t[i]);
	for (int i = 0; i < n; i++)
		if (t[i] > k) f[i] -= t[i] - k;
	int max = f[0];
	for (int i = 1; i < n; i++)
		if (f[i] > max) max = f[i];
	printf("%d\n", max);
	return 0;
}
