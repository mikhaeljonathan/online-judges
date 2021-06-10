#include <stdio.h>

int main (){
	int k;
	scanf("%d", &k);
	int pecahan[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
	for (int i = 9; i >= 0; i--){
		if (k / pecahan[i] > 0){
			printf("%d %d\n", pecahan[i], k / pecahan[i]);
			k %= pecahan[i];
		}
	}
	
	return 0;
}
