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
	while (1){
		int t;
		scanf("%d", &t);
		if (t == 0) break;
		int num[t];
		for (int i = 0; i < t; i++) scanf("%d", &num[i]);
		mergeSort(num, 0, t - 1);
		for (int i = 0; i < t; i++){
			printf("%d", num[i]);
			if (i != t - 1) printf(" ");
		}
		puts("");
	}
	return 0;
}
