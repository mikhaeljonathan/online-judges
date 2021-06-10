#include <stdio.h>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int num[n];
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	
	long long total = 0;
	for (int i = 0; i < m; i++){
		total += num[i];
	}
	long long max = total;
	
	int left, right;
	for (left = 1, right = m; right < n; left++, right++){
		total -= num[left - 1];
		total += num[right];
		if (total > max) max = total;
	}
	printf("%lld\n", max);
	return 0;
}
