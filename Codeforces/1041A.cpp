#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main (){
	int n;
	scanf("%d", &n);
	int indices[n];
	for (int i = 0; i < n; i++) scanf("%d", &indices[i]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (indices[j] > indices[j + 1]) swap(&indices[j], &indices[j + 1]);
	int res = indices[n - 1] - indices[0] + 1 - n;
	printf("%d\n", res);
	return 0;
}
