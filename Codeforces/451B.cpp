#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void merge(int a[], int aLeft, int aRight, int bLeft, int bRight){
	int size = bRight - aLeft + 1;
	int temp[size];
	int aIndex = aLeft;
	int bIndex = bLeft;
	int tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight){
		if (a[aIndex] < a[bIndex]) temp[tIndex++] = a[aIndex++];
		else temp[tIndex++] = a[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = a[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = a[bIndex++];
	
	for (int i = 0; i < size; i++) a[aLeft + i] = temp[i];
}

void mergeSort(int a[], int left, int right){
	if (left == right) return;
	else {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, mid + 1, right);
	}
}

int main (){
	int n;
	scanf("%d", &n);
	int a[n + 1];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	a[n] = 1000000001;
	int left = 0;
	int right = 0;
	int descending = 0;
	for (int i = 0; i < n; i++){
		if (a[i + 1] < a[i] && !descending){
			left = i;
			descending = 1;
		}
		if (a[i + 1] > a[i] && descending){
			right = i;
			break;
		}
	}
	mergeSort(a, left, right);
	int ascending = 1;
	for (int i = 0; i < n; i++){
		if (a[i + 1] < a[i]){
			ascending = 0;
			break;
		}
	}
	
	if (ascending){
		puts("yes");
		printf("%d %d\n", left + 1, right + 1);
	} else {
		puts("no");
	}
	return 0;
}
