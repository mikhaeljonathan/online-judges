#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main (){
	int n;
	scanf("%d", &n);
	int num[n];
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	
	int res = 0;
	for (int i = 0; i < n; i++){
		int indexmin = i;
		for (int j = i + 1; j < n; j++) if (num[j] < num[indexmin]) indexmin = j;
		swap(&num[i], &num[indexmin]);
		if (i != indexmin) res++;
	}
	
	printf("%d\n", res);
	return 0;
}
