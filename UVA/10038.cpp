#include <stdio.h>

int jolly(int num[], int n){
	for (int i = 1; i <= n; i++){
		if (!num[i]) return 0;
	}
	return 1;
}

int main (){
	long long n;
	while (scanf("%lld", &n) != EOF){
		int num[n + 1];
		for (int i = 0; i <= n; i++) num[i] = 0;
		for (int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			if (x > 0 && x <= n) num[x] = 1;
		}
		printf("%s\n", (jolly(num, n)) ? "Jolly" : "Not jolly");
	}
	
	return 0;
}
