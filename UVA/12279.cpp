#include <stdio.h>

int main (){
	int n;
	int cases = 1;
	while (scanf("%d", &n)){
		if (n == 0) break;
		int a = 0;
		int b = 0;
		while (n--){
			int x;
			scanf("%d", &x);
			if (x > 0) a++;
			else b++;
		}
		printf("Case %d: %d\n", cases++, a - b);
	}
	return 0;
}
