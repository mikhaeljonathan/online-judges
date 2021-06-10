#include <stdio.h>
#include <math.h>

int max(int a, int b){
	if (a > b) return a;
	return b;
}

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	int res = 0;
	for (int i = 0; i <= max(n, m); i++)
		for (int j = 0; j <= max(n, m); j++)
			if (i * i + j == n && i + j * j == m) res++;
	printf("%d\n", res);
	return 0;
}
