#include <stdio.h>

int main () {
	int n;
	char temp1[] = "I hate";
	char temp2[] = "I love";
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		if (i % 2) printf("%s", temp1);
		else printf("%s", temp2);
		if (i != n) printf(" that ");
	}
	printf(" it\n");
	return 0;
}
