#include <stdio.h>
int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		long long res = 0;
		int num;
		scanf("%d", &num);
		
		int n = num/4;
		res += n * (8 + (n - 1) * 4) / 2;
		
		n = num/7;
		res += n * (14 + (n - 1) * 7) / 2;
		
		n = num/28;
		res -= n * (56 + (n - 1) * 28) / 2;
		
		printf("%lld\n", res);
	}
	return 0;
}
