#include <stdio.h>

void merge(long long t[], int aLeft, int aRight, int bLeft, int bRight){
	int size = bRight - aLeft + 1;
	long long temp[size];
	int aIndex = aLeft;
	int bIndex = bLeft;
	int tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight){
		if (t[aIndex] <= t[bIndex]) temp[tIndex++] = t[aIndex++];
		else temp[tIndex++] = t[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = t[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = t[bIndex++];
	
	for (int i = 0; i < size; i++) t[aLeft + i] = temp[i];
}

void mergeSort(long long t[], int left, int right){
	if (left == right) return;
	else {
		int mid = (left + right) / 2;
		mergeSort(t, left, mid);
		mergeSort(t, mid + 1, right);
		merge(t, left, mid, mid + 1, right);
	}
}

int main (){
	int n;
	scanf("%d", &n);
	long long t[n];
	for (int i = 0; i < n; i++) scanf("%lld", &t[i]);
	mergeSort(t, 0, n - 1);
	long long total = 0;
	int res = 0;
	for (int i = 0; i < n; i++){
		if (total <= t[i]) {
			res++;
			total += t[i];
		}
	}
	printf("%d\n", res);
	return 0;
}
