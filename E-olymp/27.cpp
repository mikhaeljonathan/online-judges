#include <stdio.h>

int bits[100];
int index;

void modifybits(){
	int temp = bits[index-1];
	for (int i = index - 1; i > 0; i--){
		bits[i] = bits[i - 1];
	}
	bits[0] = temp;
}

int countbits(){
	int ret = 0;
	for (int i = 0; i < index; i++){
		if (bits[i] == 1){
			ret += 1<<i;
		}
	}
	return ret;
}

int main (){
	int n;
	scanf("%d", &n);
	index = 0;
	int temp = n;
	while (temp != 0){
		bits[index++] = temp % 2;
		temp = temp>>1;
	}
	int max = -1;
	for (int i = 0; i < index; i++){
		modifybits();
		int temp = countbits();
		if (temp > max) max = temp;
	}
	printf("%d\n", max);
	
	return 0;
}
