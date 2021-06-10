#include <stdio.h>

int main () {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int n;
		scanf("%d", &n);
		int high = 0;
		int low = 0;
		int before;
		for (int j = 1; j <= n; j++){
			int wall;
			scanf("%d", &wall);
			if (j != 1){
				if (wall > before){
					high++;
				} else if (wall < before){
					low++;
				}
			}
			before = wall;
		}
		printf("Case %d: %d %d\n", i, high, low);
	}
	return 0;
}
