#include <stdio.h>

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

int main (){
	int n;
	scanf("%d", &n);
	int coins[n];
	int total = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &coins[i]);
		total += coins[i];
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (coins[j] < coins[j + 1]) swap(&coins[j], &coins[j + 1]);
	int i = 0;
	int count = 0;
	for (; i < n; i++){
		count += coins[i];
		total -= coins[i];
		if (count > total) break;
	}
	printf("%d\n", i + 1);
	return 0;
}
