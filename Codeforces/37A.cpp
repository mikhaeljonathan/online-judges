#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main () {
	int n;
	scanf("%d", &n);
	int num[n];
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (num[j] > num[j + 1]) swap(&num[j], &num[j + 1]);
	int temp = num[0];
	int heightLargest = 1;
	int total = 1;
	int height = 1;
	for (int i = 1; i < n; i++){
		if (temp == num[i]){
			height++;
			if (height > heightLargest) heightLargest = height;
		} else {
			total++;
			height = 1;
		}
		temp = num[i];
	}
	printf("%d %d\n", heightLargest, total);
	return 0;
}
