#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int func(int a[], int k){
	int count = 0;
	for (int i = 0; i <= 12; i++){
		if (count >= k) return i;
		count += a[i];
	}
	return -1;
}

int main () {
	int k;
	scanf("%d", &k);
	int a[12];
	for (int i = 0; i < 12; i++) scanf("%d", &a[i]);
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11 - i; j++)
			if (a[j] < a[j + 1]) swap(&a[j], &a[j + 1]);
	int index = func(a, k);
	printf("%d\n", index);
	return 0;
}
