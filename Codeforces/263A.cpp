#include <stdio.h>

int abs(int x){
	if (x < 0) return -x;
	else return x;
}

int main (){
	int onex, oney;
	int num;
	for (int i = 1; i <= 5; i++){
		for (int j = 1; j <= 5; j++){
			scanf("%d", &num);
			if (num == 1){
				onex = i;
				oney = j;
			}
		}
	}
	
	int res = abs(onex - 3) + abs(oney - 3);
	printf("%d\n", res);
	return 0;
}
