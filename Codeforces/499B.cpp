#include <stdio.h>
#include <string.h>

int main (){
	int n, m;
	scanf("%d %d", &n, &m);
	char a[m][15];
	char b[m][15];
	for (int i = 0; i < m; i++){
		getchar();
		scanf("%s %s", a[i], b[i]);
	}
	for (int i = 0; i < n; i++){
		char c[15];
		getchar();
		scanf("%s", c);
		for (int j = 0; j < m; j++){
			if (!strcmp(c, a[j])){
				printf("%s", ( strlen(a[j]) <= strlen(b[j]) ) ? a[j] : b[j]);
				if (i != n - 1){
					printf(" ");
				}
				break;
			}
		}
	}
	puts("");
	return 0;
}
