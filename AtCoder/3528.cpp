#include <stdio.h>

int main () {
	int n;
	scanf("%d", &n);
	
	bool contained = (n % 10 == 9) || (n / 10 == 9);
	
	if (contained){
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
}
