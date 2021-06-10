#include <stdio.h>

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	int res = -1;
	int start = (n % 2 == 0) ? n / 2 : n / 2 + 1;
	for (int i = start; i <= n; i++){
		if (i % m == 0){
			res = i;
			break;
		}
	}
	printf("%d\n", res);
}
