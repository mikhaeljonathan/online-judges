#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int arr[n], i, x;
	int total = 0;
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (arr[i] > x) total += 3;
		else if (arr[i] == x) total += 1;
	}
	printf("%d\n", total);
	return 0;
}
