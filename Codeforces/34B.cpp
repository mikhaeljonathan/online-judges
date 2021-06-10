#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main (){
	int m, n;
	scanf("%d %d", &m, &n);
	int num[m];
	for (int i = 0; i < m; i++) scanf("%d", &num[i]);
	for (int i = 0; i < m - 1; i++)
		for (int j = 0; j < m - i - 1; j++)
			if (num[j] > num[j + 1]) swap(&num[j], &num[j + 1]);
	int res = 0;
	for (int i = 0; i < n; i++)
		if (num[i] < 0) res -= num[i];
	printf("%d\n", res);
	return 0;
}
