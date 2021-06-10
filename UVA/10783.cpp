#include <stdio.h>

int main (){
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		int temp = (a + 1) / 2;
		int res1 = temp * (1 + (temp - 1));
		
		temp = (b + 1) / 2;
		int res2 =  temp * (1 + (temp - 1));
		
		res2 -= res1;
		if (a % 2 == 1) res2 += a;
		printf("Case %d: %d\n", i, res2);		
	}
	return 0;
}
