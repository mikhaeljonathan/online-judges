#include <stdio.h>

int main (){
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	int min = 2000;
	while (n--){
		int s;
		scanf("%d", &s);
		if (s < min) min = s;
	}
	
	int max = 0;
	while (m--){
		int b;
		scanf("%d", &b);
		if (b > max) max = b;
	}
	
	if (max > min){
		int quantity = r / min;
		r -= min * quantity;
		r += max * quantity;
	}
	printf("%d\n", r);
	return 0;
}
