#include <stdio.h>

int main () {
	int n;
	scanf("%d", &n);
	int res = 0;
	for (int a = 0; a < n; a++){
		int b, c, d;
		scanf("%d %d %d", &b, &c, &d);
		int counter = 0;
		if (b == 1){
			counter++;	
		}
		if (c == 1) {
			counter++;
		}
		if (d == 1) {
			counter++;
		}
		
		if (counter >= 2){
			res++;
		}
	}
	printf("%d\n", res);
	
	return 0;
}
