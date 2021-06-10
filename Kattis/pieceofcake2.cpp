#include <stdio.h>

int max(int a, int b){
	if (a > b) return a;
	return b;
}

int main (){
	int n, h, v;
	scanf("%d %d %d", &n, &h, &v);
	int res = 4 * max(h, n - h) * max(v, n - v);
	printf("%d\n", res);
	return 0;
}
