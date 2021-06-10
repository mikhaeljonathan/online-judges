#include <stdio.h>

int main (){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	int count = 0;
	for (int i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		if (num == 1){
			if (m > 0) m--;
			else count++;
		}
		if (num == 2){
			if (k > 0) k--;
			else if (m > 0) m--;
			else count++;
		}
	}
	
	printf("%d\n", count);
}
