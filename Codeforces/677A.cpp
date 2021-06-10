#include <stdio.h>

int main () {
	int n, h;
	scanf("%d %d", &n, &h);
	int res = 0;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		if (a > h){
			res++;
		}
	}
	res += n;
	printf("%d\n", res);
	return 0;
}
