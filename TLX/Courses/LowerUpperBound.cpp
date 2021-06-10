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

int getfloor(int num[], int left, int right, int l){
	int floor = -1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (num[mid] == l){
			while (num[mid] == l && mid >= 0) mid--;
			return mid + 1;
		} else if (num[mid] > l){
			floor = mid;
			right = mid - 1;
		} else{
			left = mid + 1;
		}
	}
	return floor;
}

int getceil(int num[], int left, int right, int r){
	int ceil = -1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (num[mid] == r){
			while (num[mid] == r && mid <= right) mid++;
			return mid - 1;
		} else if (num[mid] > r){
			right = mid - 1;
		} else{
			ceil = mid;
			left = mid + 1;
		}
	}
	return ceil;
}

int main (){
	int n;
	scanf("%d", &n);
	int num[n];
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	int q;
	scanf("%d", &q);
	mergeSort(num, 0, n - 1);
	while (q--){
		int l, r;
		scanf("%d %d", &l, &r);
		
		int indexleft = getfloor(num, 0, n - 1, l);
		int indexright = getceil(num, 0, n - 1, r);
		
		printf("%d\n", indexright - indexleft + 1);
	}
	return 0;
}
