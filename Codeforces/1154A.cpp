#include <stdio.h>

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main (){
	int num[4];
	for (int i = 0; i < 4; i++) scanf("%d", &num[i]);
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3 - i; j++) if (num[j] > num[j + 1]) swap(num[j], num[j + 1]);
	printf("%d %d %d\n", num[3] - num[0], num[3] - num[1], num[3] - num[2]);
	return 0;
}
