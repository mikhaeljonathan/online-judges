#include <stdio.h>

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main (){
	int a[4];
	int temp = -1;
	int count = 0;
	int num;
	for (int i = 0; i < 4; i++)	scanf("%d", &a[i]);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3 - i; j++)
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		
	for (int i = 0; i < 4; i++){
		if (temp != a[i]) count++;
		temp = a[i];
	}
			
	count = 4 - count;
	printf("%d\n", count);
	return 0;
}
