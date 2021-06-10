#include <stdio.h>

void merge(long long c[], long long aLeft, long long aRight, long long bLeft, long long bRight){
	long long size = bRight - aLeft + 1;
	long long temp[size];
	long long aIndex = aLeft;
	long long bIndex = bLeft;
	long long tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight){
		if (c[aIndex] <= c[bIndex]) temp[tIndex++] = c[aIndex++];
		else temp[tIndex++] = c[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = c[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = c[bIndex++];
	
	for (long long i = 0; i < size; i++) c[aLeft + i] = temp[i];
}

void mergeSort(long long c[], long long left, long long right){
	if (left == right) return;
	else {
		long long mid = (left + right) / 2;
		mergeSort(c, left, mid);
		mergeSort(c, mid + 1, right);
		merge(c, left, mid, mid + 1, right);
	}
}

int main (){
	long long n, x;
	scanf("%lld %lld", &n, &x);
	long long c[n];
	for (long long i = 0; i < n; i++) scanf("%lld", &c[i]);
	mergeSort(c, 0, n - 1);
	long long res = 0;
	for (long long i = 0; i < n; i++) {
		res += x * c[i];
		if (x > 1) x--;
	}
	printf("%lld\n", res);
	return 0;
}
