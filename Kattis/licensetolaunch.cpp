#include <stdio.h>

int main () {
	int n;
	scanf("%d", &n);
	int days[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &days[i]);
	}
	int min = days[0];
	int res = 0;
	for (int i = 1; i < n; i++){
		if (days[i] < min){
			min = days[i];
			res = i;
		}
	}
	printf("%d\n", res);
	return 0;
}
