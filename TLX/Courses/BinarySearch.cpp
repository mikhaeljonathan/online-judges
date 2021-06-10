#include <stdio.h>

typedef struct{
	int entry;
	int index;
}NUM;

void merge(NUM num[], int aLeft, int aRight, int bLeft, int bRight){
	int size = bRight - aLeft + 1;
	NUM temp[size];
	int aIndex = aLeft;
	int bIndex = bLeft;
	int tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight){
		if (num[aIndex].entry <= num[bIndex].entry) temp[tIndex++] = num[aIndex++];
		else temp[tIndex++] = num[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = num[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = num[bIndex++];
	
	for(int i = 0; i < size; i++) num[aLeft + i] = temp[i];
}

void mergeSort(NUM num[], int left, int right){
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
	NUM num[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &num[i].entry);
		num[i].index = i;
	}
	mergeSort(num, 0, n - 1);
	int q;
	scanf("%d", &q);
	while (q--){
		int d;
		scanf("%d", &d);
		int res = -1;
		int left = 0;
		int right = n - 1;
		while (left <= right && res == -1){
			int mid = (left + right) / 2;
			if (d < num[mid].entry) right = mid - 1;
			else if (d > num[mid].entry) left = mid + 1;
			else res = mid;
		}
		if (res != -1){
			while (d == num[res].entry){
				res--;
			} 
			res++;
			printf("%d\n", num[res].index);
		} else {
			printf("-1\n");
		}
		
	}
	return 0;
}
