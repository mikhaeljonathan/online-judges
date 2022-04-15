#include <stdio.h>
#include <algorithm>


int main (){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	std::sort(a, a+n);
	for (int i = 0; i < n; i++){
		printf("%d", a[i]);
		if (i != n - 1) printf(" ");
	}
	printf("\n");
	return 0;
}
