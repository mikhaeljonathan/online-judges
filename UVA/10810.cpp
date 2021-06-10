#include <stdio.h>

long long res = 0;

void merge(long long num[], long long aLeft, long long aRight, long long bLeft, long long bRight){
	long long size = bRight - aLeft + 1;
	long long temp[size];
	long long aIndex = aLeft;
	long long bIndex = bLeft;
	long long tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight) {
		if (num[aIndex] <= num[bIndex]) temp[tIndex++] = num[aIndex++];
		else{
			temp[tIndex++] = num[bIndex++];	
			res += aRight - aIndex + 1;
		}
	}
	
	while (aIndex <= aRight) temp[tIndex++] = num[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = num[bIndex++];
	
	for (long long i = 0; i < size; i++) num[aLeft + i] = temp[i];
}

void mergeSort(long long num[], long long left, long long right){
	if (left == right) return;
	else {
		long long mid = (left + right) / 2;
		mergeSort(num, left, mid);
		mergeSort(num, mid + 1, right);
		merge(num, left, mid, mid + 1, right);
	}
}

int main (){
	long long n;
	scanf("%lld", &n);
	while (n != 0){
		res = 0;
		long long num[n];
		for (long long i = 0; i < n; i++) scanf("%lld", &num[i]);
		mergeSort(num, 0, n - 1);
		printf("%lld\n", res);
		scanf("%lld", &n);
	}
	return 0;
}
