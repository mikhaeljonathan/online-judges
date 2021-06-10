#include <stdio.h>
#include <algorithm>

int main () {
	int t;
	scanf("%d", &t);
	while (t--){
		int n, k;
		scanf("%d %d", &n, &k);
		long long height[n];
		for (int i = 0; i < n; i++){
			scanf("%lld", &height[i]);
		}
		
		if (k == 1){
			printf("0\n");
		} else {
			std::sort(height, height + n);
			long long min = 1000000005;
			for (int i = 0; i < n - k + 1; i++){
				if (height[i + k - 1] - height[i] < min){
					min = height[i + k - 1] - height[i];
				}
			}
			printf("%lld\n", min);
		}
	}
	return 0;
}
