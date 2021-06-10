#include <stdio.h>

int main (){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		int min = 1 << 30;
		int max = 0;
		while (n--){
			int x;
			scanf("%d", &x);
			if (x < min) min = x;
			if (x > max) max = x;
		}
		printf("%d\n", 2 * (max - min));
	}
	return 0;
}
