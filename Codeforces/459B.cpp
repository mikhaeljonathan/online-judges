#include <stdio.h>

void merge(int b[], int aLeft, int aRight, int bLeft, int bRight){
	int size = bRight - aLeft + 1;
	int temp[size];
	int aIndex = aLeft;
	int bIndex = bLeft;
	int tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight){
		if (b[aIndex] <= b[bIndex]) temp[tIndex++] = b[aIndex++];
		else temp[tIndex++] = b[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = b[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = b[bIndex++];
	
	for (int i = 0; i < size; i++) b[aLeft + i] = temp[i];
}

void mergeSort(int b[], int left, int right){
	if (left == right) return;
	else {
		int mid = (left + right) / 2;
		mergeSort(b, left, mid);
		mergeSort(b, mid + 1, right);
		merge(b, left, mid, mid + 1, right);
	}
}

bool homogenous(int b[], int n){
	int temp = b[0];
	for (int i = 0; i < n; i++)
		if (b[i] != temp) return false;
	return true;
}

int main (){
	int n;
	scanf("%d", &n);
	int b[n];
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	mergeSort(b, 0, n - 1);
	if (homogenous(b, n)){
		long long temp1 = (n % 2) ? (n - 1) : n;
		long long temp2 = (n % 2) ? n : (n - 1);
		long long temp = temp1 / 2 * temp2;
		printf("%d %lld\n", b[n - 1] - b[0], temp);
	}
	else {
		long long res1 = 0;
		//min
		int temp = b[0];
		for (int i = 0; i < n; i++)
			if (b[i] == temp) res1++;
			else break;
		//max
		long long res2 = 0;
		temp = b[n - 1];
		for (int i = n - 1; i >= 0; i--)
			if (b[i] == temp) res2++;
			else break;
		long long res = res1 * res2;
		printf("%d %lld\n", b[n - 1] - b[0], res);
	}
	return 0;
}
