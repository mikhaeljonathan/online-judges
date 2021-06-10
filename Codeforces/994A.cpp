#include <stdio.h>

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	int x[n], y[m];
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	for (int i = 0; i < m; i++) scanf("%d", &y[i]);
	bool first = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			if (x[i] == y[j]){
				if (first) first = false;
				else printf(" ");
				printf("%d", x[i]);
			} 
		}
	}
	return 0;
}
