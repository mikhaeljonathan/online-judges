#include <stdio.h>

int res(int x){
	if (x == 1) return 1;
	else return (x % 2) + res(x / 2);
}

int main (){
	int x;
	scanf("%d", &x);
	printf("%d\n", res(x));
	return 0;
}
