#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int p[n], q[n];
	for (int i = 0; i < n; i++) scanf("%d %d", &p[i], &q[i]);
	int res = 0;
	for (int i = 0; i < n; i++)
		if (q[i] - p[i] >= 2) res++;
	printf("%d\n", res);
	return 0;
}
