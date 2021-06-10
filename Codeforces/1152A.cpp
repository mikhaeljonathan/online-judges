#include <stdio.h>

int min (int a, int b){
	return (a < b) ? a : b;
}

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	int aodd = 0;
	int aeven = 0;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		if (a % 2) aodd++;
		else aeven++;
	}
	int bodd = 0;
	int beven = 0;
	for (int i = 0; i < m; i++){
		int b;
		scanf("%d", &b);
		if (b % 2) bodd++;
		else beven++;
	}
	int res = min(aodd, beven) + min(aeven, bodd);
	printf("%d\n", res);
	return 0;
}
