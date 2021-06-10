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
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (num[j] > num[j + 1]){
				swap(&num[j], &num[j + 1]);
				res++;
			}
		}
	}
	
	printf("%d\n", res);
	return 0;
}
