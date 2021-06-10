#include <stdio.h>

struct laptop{
	int price;
	int quality;
};

void swap(laptop *a, laptop *b){
	laptop temp = *b;
	*b = *a;
	*a = temp;
}

bool test (laptop a[], int n){
	int temp = 0;
	for (int i = 0; i < n; i++){
		if (a[i].quality < temp) return true;
		temp = a[i].quality;
	}
	return false;
}

void merge(laptop a[], int aLeft, int aRight, int bLeft, int bRight){
	int size = bRight - aLeft + 1;
	laptop temp[size];
	int aIndex = aLeft;
	int bIndex = bLeft;
	int tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight){
		if (a[aIndex].price <= a[bIndex].price) temp[tIndex++] = a[aIndex++];
		else temp[tIndex++] = a[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = a[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = a[bIndex++];
	
	for (int i = 0; i < size; i++) a[aLeft + i] = temp[i];
}

void mergeSort(laptop a[], int left, int right){
	if (left == right) return;
	else {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, mid + 1, right);
	}
}

int main () {
	int n;
	scanf("%d", &n);
	laptop a[n];
	for (int i = 0; i < n; i++) scanf("%d %d", &a[i].price, &a[i].quality);
	mergeSort(a, 0, n - 1);
	printf("%s\n", (test(a, n)) ? "Happy Alex" : "Poor Alex");
	return 0;
}
