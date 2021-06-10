#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main (){
	int n, k;
	scanf("%d %d", &n, &k);
	int y[n];
	for (int i = 0; i < n; i++) scanf("%d", &y[i]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (y[j] > y[j + 1]) swap(&y[j], &y[j + 1]);
	int i = 0;
	for (; i < n; i++)
		if (y[i] + k > 5) break;
	
	printf("%d\n", i / 3);
	return 0;
}
