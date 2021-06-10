#include <stdio.h>

int main (){
	int n;
	scanf("%d", &n);
	int num[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	
	int min = num[n - 1], res = n;
	int temp;
	for (int i = n - 2; i >= 0; i--){
		if (num[i] <= min){
			min = num[i];
			temp = i;
		}
	}
	
	for (int i = temp + 1; i < n; i++){
		if (num[i] == min){
			if (i - temp <= res) res = i - temp;
			temp = i;
		}
	}
	printf("%d\n", res);
	return 0;
}
