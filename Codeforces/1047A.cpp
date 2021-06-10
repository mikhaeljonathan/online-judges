#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		if (i % 3 == 0) continue;
		int temp = n - 2 * i;
		if (temp % 3 != 0){
			printf("%d %d %d\n", i, i, temp);
			break;
		}
	}
	return 0;
}
