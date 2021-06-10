#include <stdio.h>

int main () {
	int num[3], k;
	scanf("%d %d %d %d", &num[0], &num[1], &num[2], &k);
	
	
	for (int i = 1; i <= k; i++){
		
		int max = (num[0] > num[1]) ? num[0] : num[1];
		max = (max > num[2]) ? max : num[2];
		
		for (int j = 0; j < 3; j++){
			if (num[j] == max){
				num[j] *= 2;
				break;
			}
		}
	
	}
	printf("%d\n", num[0] + num[1] + num[2]);
	
	return 0;
}
