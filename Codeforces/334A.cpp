#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int left = 1;
	int right = n * n;
	bool first;
	for (int i = 0; i < n; i++){
		first = true;
		for (int j = 0; j < n / 2; j++){
			if (first) first = false;
			else printf(" ");
			printf("%d", left);
			left++;
		}
		
		for (int j = 0; j < n / 2; j++){
			printf(" %d", right);
			right--;
		}
		puts("");
	}
	return 0;
}
