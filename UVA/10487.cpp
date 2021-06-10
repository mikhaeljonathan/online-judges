#include <stdio.h>

int abs(int x){
	return (x < 0) ? -x : x;
}

int main (){
	int n;
	int tc = 1;
	while (scanf("%d", &n) && n != 0){
		int idx = 0;
		int num[n];
		for (int i = 0; i < n; i++) scanf("%d", &num[i]);
		int sums[n * n];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				sums[idx++] = num[i] + num[j];
		
		int m;
		scanf("%d", &m);
		
		printf("Case %d:\n", tc++);
		
		while (m--){
			int query;
			scanf("%d", &query);
			
			int min = 1 << 30;
			int res = -1;
			for (int i = 0; i < idx; i++){
				if (abs(sums[i] - query) < min){
					min = abs(sums[i] - query);
					res = sums[i];
				} 
			}
				
			printf("Closest sum to %d is %d.\n", query, res);
		}
		
	}
	return 0;
}
