#include <stdio.h>

int main (){
	int a, b;
	scanf("%d %d", &a, &b);
	int res = 0;
	while (a <= b){
		a *= 3;
		b *= 2;
		res++;
	}
	printf("%d\n", res);
	return 0;
}
