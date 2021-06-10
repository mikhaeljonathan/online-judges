#include <stdio.h>

void merge(int num[], int aLeft, int aRight, int bLeft, int bRight){
	int size = bRight - aLeft + 1;
	int temp[size];
	int aIndex = aLeft;
	int bIndex = bLeft;
	int tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight){
		if (num[aIndex] <= num[bIndex]) temp[tIndex++] = num[aIndex++];
		else temp[tIndex++] = num[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = num[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = num[bIndex++];
	
	for (int i = 0; i < size; i++) num[aLeft + i] = temp[i];
}

void mergeSort(int num[], int left, int right){
	if (left == right) return;
	else {
		int mid = (left + right) / 2;
		mergeSort(num, left, mid);
		mergeSort(num, mid + 1, right);
		merge(num, left, mid, mid + 1, right);
	}
}

int main (){
	int n;
	scanf("%d", &n);
	int num[n];
	for (int i = 0; i < n; i++)	scanf("%d", &num[i]);
	mergeSort(num, 0, n - 1);
	double res;
	if (n % 2){
		res = (double) num[n / 2];
	} else {
		res = ((double) num[n / 2 - 1] + (double) num[n / 2] ) / 2.0;
	}
	printf("%.2lf\n", res);
	return 0;
}
