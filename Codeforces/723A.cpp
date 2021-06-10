#include <stdio.h>

int main (){
	int x1, x2, x3;
	scanf("%d %d %d", &x1, &x2, &x3);
	int max = (x1 > x2) ? x1 : x2;
	max = (max > x3) ? max : x3;
	
	int min = (x1 > x2) ? x2 : x1;
	min = (min > x3) ? x3 : min;
	
	printf("%d\n", max - min);
	return 0;
}
