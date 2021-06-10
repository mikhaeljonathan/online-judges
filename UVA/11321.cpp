#include <stdio.h>

typedef struct{
	int value;
	int mod;
}data;

int abs (int x){
	return (x < 0) ? -x : x;
}

int compare (data a, data b){
	if (a.mod != b.mod) return (a.mod < b.mod);
	else {
		if (abs(a.value) % 2 != abs(b.value) % 2){
			if (abs(a.value) % 2) return 1;
			else return 0;	
		}
		if (abs(a.value) % 2 == 1 && abs(b.value) % 2 == 1){
			if (a.value > b.value) return 1;
			else return 0;
		}
		if (abs(a.value) % 2 == 0 && abs(b.value) % 2 == 0){
			if (a.value < b.value) return 1;
			else return 0;
		}
	}
}

void merge(data arr[], int aLeft, int aRight, int bLeft, int bRight){
	int size = bRight - aLeft + 1;
	data temp[size];
	int aIndex = aLeft;
	int bIndex = bLeft;
	int tIndex = 0;
	
	while (aIndex <= aRight && bIndex <= bRight){
		if (compare(arr[aIndex], arr[bIndex])) temp[tIndex++] = arr[aIndex++];
		else temp[tIndex++] = arr[bIndex++];
	}
	
	while (aIndex <= aRight) temp[tIndex++] = arr[aIndex++];
	
	while (bIndex <= bRight) temp[tIndex++] = arr[bIndex++];
	
	for (int i = 0; i < size; i++) arr[aLeft + i] = temp[i];
}

void mergeSort(data arr[], int left, int right){
	if (left == right) return;
	else {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, mid + 1, right);
	}
}

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	while (n != 0 && m != 0){
		data arr[n];
		for (int i = 0; i < n; i++){
			scanf("%d", &arr[i].value);
			arr[i].mod = arr[i].value % m;
		}
		mergeSort(arr, 0, n - 1);
		printf("%d %d\n", n, m);
		for (int i = 0; i < n; i++) printf("%d\n", arr[i].value);
		scanf("%d %d", &n, &m);
	}
	puts("0 0");
	return 0;
}
