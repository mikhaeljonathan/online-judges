#include <stdio.h>

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main (){
	int arr[10005];
	int index = 0;
	while (scanf("%d", &arr[index]) != EOF){
		int pos = index;
		while ((pos > 0) && (arr[pos] < arr[pos - 1])){
			swap(arr[pos], arr[pos - 1]);
			pos--;
		}
		if (index == 0) printf("%d\n", arr[index]);
		else {
			if (index % 2 == 0) printf("%d\n", arr[index / 2]);
			else printf("%d\n", (arr[index / 2] + arr[index / 2 + 1]) / 2);
		}
		index++;
	}
	return 0;
}
