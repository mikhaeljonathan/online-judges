#include <stdio.h>

int min(int a, int b){
	return (a < b) ? a : b;
}

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int minPrice[n];
		minPrice[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) minPrice[i] = min(minPrice[i + 1], a[i]);
		int res = 0;
		for (int i = 0; i < n; i++) if (a[i] != minPrice[i]) res++;
		printf("%d\n", res);
	}
	return 0;
}
