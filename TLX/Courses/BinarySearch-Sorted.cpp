#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int num[n];
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	int q;
	scanf("%d", &q);
	while (q--){
		int d;
		scanf("%d", &d);
		int res = -1;
		int left = 0;
		int right = n - 1;
		while (left <= right && res == -1){
			int mid = (left + right) / 2;
			if (d < num[mid]) right = mid - 1;
			else if (d > num[mid]) left = mid + 1;
			else res = mid;
		}
		if (res != -1){
			while (d == num[res]){
				res--;
			} 
			res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
