#include <stdio.h>

int main () {
	int n;
	scanf("%d", &n);
	int min = 1000;
	int total = 0;
	for (int i = 0; i < n; i++){
		int c;
		scanf("%d", &c);
		total += c;
		if (c < min){
			min = c;
		}
	}
	total -= min;
	printf("%d\n", total);
	return 0;
}
