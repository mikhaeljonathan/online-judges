#include <stdio.h>

bool test(int bulb[], int m){
	for (int i = 1; i <= m; i++) if (bulb[i] == 0) return false;
	return true;
}

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	int bulb[m + 1];
	for (int i = 1; i <= m; i++) bulb[i] = 0;
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		for (int j = 0; j < x; j++){
			int y;
			scanf("%d", &y);
			bulb[y] = 1;
		}
	}
	printf("%s\n", (test(bulb, m)) ? "YES" : "NO");
	return 0;
}
