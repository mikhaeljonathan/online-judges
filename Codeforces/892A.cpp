#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	long long b[n];
	long long total = 0;
	long long remaining;
	for (int i = 0; i < n; i++){
		scanf("%lld", &remaining);
		total += remaining;
	}
	for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
	long long max1 = b[0];
	int index = 0;
	for (int i = 0; i < n; i++){
		if (b[i] > max1){
			max1 = b[i];
			index = i;
		}
	}
	b[index] = -1;
	long long max2 = b[0];
	for (int i = 0; i < n; i++)
		if (b[i] > max2) max2 = b[i];
	
	long long max = max1 + max2;

	printf("%s\n", (total <= max) ? "YES" : "NO");
	return 0;
}
