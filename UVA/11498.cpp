#include <stdio.h>

int main (){
	int k;
	while(scanf("%d", &k) && k != 0){
		int n, m;
		scanf("%d %d", &n, &m);
		while (k--){
			int x, y;
			scanf("%d %d", &x, &y);
			if (x == n || y == m) puts("divisa");
			else if (x > n && y < m) puts("SE");
			else if (x > n && y > m) puts("NE");
			else if (x < n && y > m) puts("NO");
			else if (x < n && y < m) puts("SO");
		}
	}
	return 0;
}
