#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	bool hard = false;
	while(n--){
		int x;
		scanf("%d", &x);
		if (x == 1) hard = true;
	}
	printf("%s\n", hard ? "HARD" : "EASY");
	return 0;
}
